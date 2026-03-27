# ======================================
# IMPORTS
# ======================================

import tkinter as tk
from tkinter import messagebox
from PIL import Image, ImageTk
import csv
from datetime import datetime
from tkinter import filedialog
import os
import shutil


# ======================================
# GLOBAL VARIABLES
# ======================================

current_teacher = None
receipt_path = None


# ======================================
# LOGIC FUNCTIONS
# ======================================

def validate_login(username, password):
    valid_users = {
        "teacher1": "1234",
        "teacher2": "abcd"
    }
    return username in valid_users and valid_users[username] == password


def save_report_to_csv(teacher, students, duration, content, behavior, observations, reimbursement, receipt):

    file_exists = False

    try:
        with open("lesson_reports.csv", "r"):
            file_exists = True
    except FileNotFoundError:
        file_exists = False

    with open("lesson_reports.csv", "a", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)

        if not file_exists:
            writer.writerow([
                "Date",
                "Teacher",
                "Students",
                "Duration",
                "Content",
                "Behavior",
                "Observations",
                "Reimbursement",
                "Receipt"
            ])

        writer.writerow([
            datetime.now().strftime("%Y-%m-%d %H:%M"),
            teacher,
            students,
            duration,
            content,
            behavior,
            observations,
            reimbursement,
            receipt
        ])



# ======================================
# GUI FUNCTIONS
# ======================================

def show_frame(frame):
    frame.tkraise()


def handle_login():
    global current_teacher

    username = username_entry.get()
    password = password_entry.get()

    if validate_login(username, password):
        current_teacher = username
        show_frame(main_frame)
    else:
        messagebox.showerror("Login Error", "Invalid username or password")


def handle_submit():
    global receipt_path

    selected_indices = students_listbox.curselection()
    selected_students = [students_listbox.get(i) for i in selected_indices]

    if not selected_students:
        messagebox.showerror("Error", "Please select at least one student.")
        return

    duration = duration_entry.get()
    content = content_entry.get()
    behavior = behavior_text.get("1.0", tk.END).strip()
    observations = observations_text.get("1.0", tk.END).strip()
    reimbursement = reimbursement_var.get()

    if reimbursement == "Yes" and not receipt_path:
        messagebox.showerror("Error", "Receipt image is required for reimbursement.")
        return

    save_report_to_csv(
        current_teacher,
        ", ".join(selected_students),
        duration,
        content,
        behavior,
        observations,
        reimbursement,
        receipt_path
    )

    messagebox.showinfo("Success", "Report saved successfully!")

    clear_form()

def toggle_receipt_button():
    if reimbursement_var.get() == "Yes":
        upload_button.config(state="normal")
    else:
        upload_button.config(state="disabled")


def upload_receipt():
    global receipt_path

    file_path = filedialog.askopenfilename(
        title="Select Receipt Image",
        filetypes=[("Image Files", "*.jpg *.jpeg *.png")]
    )

    if file_path:

        # Create receipts folder if it doesn't exist
        receipts_folder = os.path.join(os.getcwd(), "receipts")

        if not os.path.exists(receipts_folder):
            os.makedirs(receipts_folder)

        # Get original filename
        filename = os.path.basename(file_path)

        # Create destination path
        destination = os.path.join(receipts_folder, filename)

        # Copy file
        shutil.copy(file_path, destination)

        # Save relative path
        receipt_path = os.path.join("receipts", filename)

        receipt_label.config(text=f"Selected: {filename}")

def clear_form():
    global receipt_path

    # Clear students selection
    students_listbox.selection_clear(0, tk.END)

    # Clear entries
    duration_entry.delete(0, tk.END)
    content_entry.delete(0, tk.END)

    # Clear text fields
    behavior_text.delete("1.0", tk.END)
    observations_text.delete("1.0", tk.END)

    # Reset reimbursement
    reimbursement_var.set("No")

    # Reset receipt
    receipt_path = None
    receipt_label.config(text="No receipt selected")

    upload_button.config(state="disabled")


# ======================================
# FRAME CREATION
# ======================================

def create_login_frame():

    frame = tk.Frame(root, bg="#f0f2f5")

    card = tk.Frame(
        frame,
        bg="white",
        padx=40,
        pady=40,
        highlightthickness=1,
        highlightbackground="#d9d9d9"
    )
    card.place(relx=0.5, rely=0.5, anchor="center")

    # LOGO
    global logo_image
    image = Image.open("logo.jpg")
    image = image.resize((200, 200))
    logo_image = ImageTk.PhotoImage(image)

    tk.Label(card, image=logo_image, bg="white").pack(pady=(0, 20))

    tk.Label(
        card,
        text="Teacher Login",
        font=("Arial", 20, "bold"),
        bg="white"
    ).pack(pady=(0, 20))

    tk.Label(card, text="Username", bg="white").pack(anchor="w")
    global username_entry
    username_entry = tk.Entry(card, width=30)
    username_entry.pack(pady=(5, 15))

    tk.Label(card, text="Password", bg="white").pack(anchor="w")
    global password_entry
    password_entry = tk.Entry(card, show="*", width=30)
    password_entry.pack(pady=(5, 20))

    tk.Button(
        card,
        text="Login",
        bg="#4a90e2",
        fg="white",
        width=20,
        command=handle_login
    ).pack()

    frame.bind_all("<Return>", lambda event: handle_login())

    return frame


def create_main_frame():

    frame = tk.Frame(root)

    tk.Label(
        frame,
        text="Tree House Lesson System",
        font=("Arial", 24)
    ).pack(pady=50)

    tk.Button(
        frame,
        text="Create Lesson Report",
        font=("Arial", 16),
        command=lambda: show_frame(form_frame)
    ).pack(pady=20)

    return frame


def create_form_frame():

    frame = tk.Frame(root)

    tk.Label(
        frame,
        text="Lesson Report Form",
        font=("Arial", 20, "bold")
    ).pack(pady=20)

    # STUDENTS
    tk.Label(frame, text="Select Students:").pack()
    global students_listbox
    students_listbox = tk.Listbox(frame, selectmode=tk.EXTENDED, width=40, height=5)
    students_listbox.pack()

    students = ["Ana", "Lucas", "Maria", "John", "Sophia"]
    for student in students:
        students_listbox.insert(tk.END, student)

    # DURATION
    tk.Label(frame, text="Duration (minutes):").pack(pady=5)
    global duration_entry
    duration_entry = tk.Entry(frame)
    duration_entry.pack()

    # CONTENT
    tk.Label(frame, text="What was taught:").pack(pady=5)
    global content_entry
    content_entry = tk.Entry(frame, width=50)
    content_entry.pack()

    # BEHAVIOR
    tk.Label(frame, text="Student behavior:").pack(pady=5)
    global behavior_text
    behavior_text = tk.Text(frame, height=3, width=50)
    behavior_text.pack()

    # OBSERVATIONS
    tk.Label(frame, text="Observations:").pack(pady=5)
    global observations_text
    observations_text = tk.Text(frame, height=3, width=50)
    observations_text.pack()

    # REIMBURSEMENT
    tk.Label(frame, text="Reimbursement needed?").pack(pady=5)
    global reimbursement_var
    reimbursement_var = tk.StringVar(value="No")

    tk.Radiobutton(
        frame,
        text="Yes",
        variable=reimbursement_var,
        value="Yes",
        command=toggle_receipt_button
    ).pack()

    tk.Radiobutton(
        frame,
        text="No",
        variable=reimbursement_var,
        value="No",
        command=toggle_receipt_button
    ).pack()


    # UPLOAD RECEIPT
    global upload_button
    upload_button = tk.Button(
    frame,
    text="Upload Receipt",
    command=upload_receipt,
    state="disabled"
    )
    upload_button.pack(pady=5)


    global receipt_label
    receipt_label = tk.Label(frame, text="No receipt selected")
    receipt_label.pack()

    # SUBMIT BUTTON
    tk.Button(
        frame,
        text="Submit Report",
        font=("Arial", 12, "bold"),
        bg="#4a90e2",
        fg="white",
        width=20,
        command=handle_submit
    ).pack(pady=20)

    tk.Button(
        frame,
        text="Back",
        command=lambda: show_frame(main_frame)
    ).pack(pady=10)

    return frame



# ======================================
# MAIN
# ======================================

def main():
    global root
    global login_frame
    global main_frame
    global form_frame

    root = tk.Tk()
    root.title("Tree House System")
    root.geometry("1200x700")
    root.resizable(False, False)


    login_frame = create_login_frame()
    main_frame = create_main_frame()
    form_frame = create_form_frame()

    for frame in (login_frame, main_frame, form_frame):
        frame.place(relwidth=1, relheight=1)

    show_frame(login_frame)

    root.mainloop()


# ======================================
# START
# ======================================

if __name__ == "__main__":
    main()

