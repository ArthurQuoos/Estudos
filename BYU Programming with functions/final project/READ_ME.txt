
Hello! 
To develop this project, I was inspired by a Google Form that 
the teachers fill out at the school where I work.

Regarding the "reimbursements" section, 
the idea is that teachers would submit Uber receipts or parking receipts.

I also used the library pillow, so to run the project make sure you install it, i think that's it

pip install pillow


## 🔐 Login Credentials (for testing)

Teacher accounts:

- Username: teacher1  
  Password: 1234  

- Username: teacher2  
  Password: abcd  

---

## 🧾 How It Works

1. User logs in.
2. User selects students.
3. User fills in lesson details.
4. If reimbursement is set to "Yes":
   - Receipt upload becomes enabled.
   - Upload is required before submission.
5. Report is saved to `lesson_reports.csv`.
6. Form resets automatically after submission.

---

## Data Storage

All reports are stored in:lesson_reports.csv


---

## Features Implemented

- Multi-screen interface (Login, Dashboard, Form)
- Form validation
- Multiple student selection
- Conditional receipt upload
- Automatic CSV creation
- Form auto-reset after submission
- Relative file paths for portability

---

## Possible Future Improvements

- Director/Admin panel to view reports
- Search and filter functionality
- Improved UI design
- Database integration (SQLite)
- Export to PDF

---

##  Author

Arthur Quoos  
---

