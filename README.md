# 📚 Library Management System (C++)

A console-based **Library Management System** developed using **C++**, **Object-Oriented Programming (OOP)** concepts, and **File Handling**.
This project helps manage library operations such as adding books, issuing books, returning books, managing student records, and password-based authentication.

The system stores records using `.dat` files for persistent data storage and provides a menu-driven interface for easy interaction. 

---

##  Features

* 📖 Add new books
* 🔍 Search books by serial number
* 📕 Issue books to students
* 📗 Return books management
* 👨‍🎓 Student record management
* 🔐 Password authentication system
* 💾 File handling using `.dat` files
* 🧾 Update and delete records
* 📂 Separate modules for books, students, issues, and authentication

---

##  Technologies Used

* **C++**
* **Object-Oriented Programming (OOP)**
* **File Handling**
* **Binary File Storage (.dat files)**
* **Console-based UI**

---

##  Folder Structure

```bash
Library-Management-System/
│
├── project.cpp          # Main program entry point
├── book.cpp             # Book management module
├── book.h
├── students.cpp         # Student management module
├── students.h
├── issue.cpp            # Issue/Return management
├── issue.h
├── password.cpp         # Authentication system
├── password.h
│
├── book.dat             # Book records storage
├── student.dat          # Student records storage
├── issue.dat            # Issue records storage
├── password.dat         # Login credentials storage
│
└── README.md
```

---

##  How to Compile and Run

### 🔹 Using g++

```bash
g++ project.cpp book.cpp students.cpp issue.cpp password.cpp -o library
```

### 🔹 Run the Program

```bash
./library
```

> For Windows users:

```bash
library.exe
```

---

## 📌 Modules Overview

### 📚 Book Management

* Add books
* Search books
* Update book records
* Delete books

Implemented using binary file handling in `book.dat`.

### 👨‍🎓 Student Management

* Add students
* Search students
* Update student records
* Delete student records

Student data is stored in `student.dat`.

### 📕 Issue Management

* Issue books
* Maintain issue dates
* Store return dates
* Validate book and student IDs

Issue records are maintained in `issue.dat`.

### 🔐 Authentication System

* Username/password verification
* Password reset functionality
* Credentials stored in `password.dat`

Authentication is handled using file-based credential checking.

---

## 💡 Future Improvements

* GUI-based interface using Qt or GTK
* Database integration (MySQL/SQLite)
* Fine calculation for late returns
* Book availability tracking
* Search by book name/author
* Admin and student roles
* Improved password encryption
* Better error handling and validation

---

## ⭐ GitHub Tip

If you like this project, consider giving it a **star ⭐** on GitHub to support the work!

