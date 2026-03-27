import os
import csv
from main import validate_login, save_report_to_csv


def test_validate_login():
    # Call 1
    result1 = validate_login("teacher1", "1234")
    # Call 2
    result2 = validate_login("teacher1", "wrong")

    # Assert 1
    assert result1 is True
    # Assert 2
    assert result2 is False


def test_save_report_to_csv(tmp_path):
    # Create temporary file
    test_file = tmp_path / "test_reports.csv"

    # Call 1
    save_report_to_csv(
        "teacher1",
        "Ana",
        "60",
        "Math",
        "Good",
        "None",
        "No",
        ""
    )

    # Call 2
    save_report_to_csv(
        "teacher2",
        "Lucas",
        "45",
        "English",
        "Excellent",
        "None",
        "Yes",
        "receipts/test.jpg"
    )

    # Assert 1: file exists
    assert os.path.exists("lesson_reports.csv")

    # Assert 2: file has content
    with open("lesson_reports.csv", "r", encoding="utf-8") as f:
        rows = list(csv.reader(f))
        assert len(rows) >= 3
