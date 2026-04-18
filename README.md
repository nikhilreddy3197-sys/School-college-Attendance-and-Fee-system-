## 📌 Student Attendance & Fee Management System (C)

### 📍 Project Title  
Student Attendance & Fee Management System Using C Programming

---

### 🎯 Objective  
The objective of this project is to develop a simple console-based system to manage student records, track attendance, and handle fee collection. This project demonstrates fundamental concepts of C programming such as linked lists, dynamic memory allocation, and menu-driven program design.

---

### 📖 Project Description  
This program maintains student records using a **singly linked list**. Each student node stores details like ID, name, attendance, and fees paid. The system allows users to efficiently manage student data through various operations.

The user can:
- Add a new student record  
- Mark attendance for a student  
- Collect fees from a student  
- View all student details  
- Generate a summary report  
- Undo the last added student entry  
- Exit the system  

The program dynamically allocates memory for each student and ensures efficient insertion and traversal using linked lists.

---

### ⚙️ Technologies Used  
- C Programming Language  
- GCC Compiler (or any standard C compiler)  
- Terminal / Command Line Interface  

---

### 🚀 Features  
- Menu-driven user interface  
- Dynamic memory allocation using linked list  
- Efficient insertion of student records  
- Attendance tracking system  
- Fee collection and update system  
- Report generation (total students, attendance, fees)  
- Undo functionality for last inserted record  
- Proper memory deallocation  

---

### ⚠️ Assumptions  
- Each student ID is unique  
- Students are inserted at the beginning of the list  
- Undo operation works only for the last added student  
- Data is not stored permanently after program exit  
- Console-based application  

---

### 📊 Sample Output  
```
1. Add Student  
2. Mark Attendance  
3. Collect Fee  
4. View Students  
5. Generate Report  
6. Undo Last Entry  
7. Exit  

Enter Student ID: 101  
Enter Student Name: Rahul  
Student added successfully  

Attendance marked. Total attendance: 1  
Fee collected. Total fee paid: 5000.00  

ID    Name      Attendance    Fees Paid  
101   Rahul     1             5000.00  

Report Summary:  
Total Students: 1  
Total Attendance Days: 1  
Total Fees Collected: 5000.00  
```

---

### 🧠 Learning Outcomes  
Students will learn how to:
- Implement singly linked lists in C  
- Use dynamic memory allocation (`malloc`, `free`)  
- Perform traversal and searching in linked lists  
- Design menu-driven applications  
- Manage real-world data using data structures  
- Handle user input and validation  

---

### 📂 Files Included  
- `student_system.c` → Main source code  
- `README.md` → Documentation  

---

### 📝 How to Compile and Run  

```bash
gcc student_system.c -o student_system
./student_system
```

**For Windows:**
```bash
student_system.exe
```

---

### 👨‍🏫 Notes for Instructor  
- Demonstrates practical use of **Linked List operations**  
- Covers insertion, traversal, searching, and deletion (undo)  
- Includes real-world application logic  
- Suitable for Data Structures lab evaluation# School-college-Attendance-and-Fee-system-
