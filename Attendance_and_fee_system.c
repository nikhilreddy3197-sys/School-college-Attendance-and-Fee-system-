#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for Student which holds student details and a pointer to the next student
typedef struct Student {
    int id;                 // Student ID
    char name[50];          // Student Name
    int attendance;         // Number of days attended
    float feesPaid;         // Total fees paid by student
    struct Student* next;   // Pointer to next student node in the linked list
} Student;

// Pointer to the head (start) of the linked list of students
Student* head = NULL;

// Function prototypes declaration
void addStudent();
void markAttendance();
void collectFee();
void viewStudents();
void generateReport();
void undoLastEntry();

// Pointer to keep track of the last added student for undo operation
Student* lastAdded = NULL;

int main() {
    int choice;
    while (1) {
        // Display menu options to user
        printf("\nSchool/College Attendance & Fee System\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. Collect Fee\n");
        printf("4. View Students\n");
        printf("5. Generate Report\n");
        printf("6. Undo Last Entry\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character from input buffer

        switch (choice) {
            case 1: addStudent(); break;        // Add new student record
            case 2: markAttendance(); break;    // Mark attendance for a student
            case 3: collectFee(); break;         // Collect fees from student
            case 4: viewStudents(); break;       // Display all student records
            case 5: generateReport(); break;     // Display summary report
            case 6: undoLastEntry(); break;      // Undo last student entry addition
            case 7: 
                // Free all allocated memory before exiting program
                printf("Exiting...\n");
                while (head != NULL) {
                    Student* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);  // Terminate program
            default:
                // Handle invalid menu choice
                printf("Invalid choice, try again.\n");
        }
    }
}

// Function to add a new student record to the linked list
void addStudent() {
    // Allocate memory dynamically for a new Student node
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    // Input student details
    printf("Enter Student ID: ");
    scanf("%d", &newStudent->id);
    getchar();  // Clear newline character from buffer
    
    printf("Enter Student Name: ");
    fgets(newStudent->name, sizeof(newStudent->name), stdin);

    // Remove trailing newline character from name input
    newStudent->name[strcspn(newStudent->name, "\n")] = 0;
    
    // Initialize attendance and feesPaid to zero for new student
    newStudent->attendance = 0;
    newStudent->feesPaid = 0.0;
    newStudent->next = NULL;

    // Insert the new student at the beginning of the linked list
    newStudent->next = head;
    head = newStudent;

    // Update lastAdded pointer to new student for undo operation
    lastAdded = newStudent;
    printf("Student added successfully.\n");
}

// Helper function to find a student node by their ID
Student* findStudent(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) return current;  // Return student if found
        current = current->next;
    }
    return NULL;  // Return NULL if student not found
}

// Function to mark attendance for a student
void markAttendance() {
    if (head == NULL) {
        // No students added yet
        printf("No students to mark attendance for.\n");
        return;
    }
    int id;
    printf("Enter Student ID to mark attendance: ");
    scanf("%d", &id);

    // Find student by ID
    Student* student = findStudent(id);
    if (student == NULL) {
        printf("Student not found.\n");
        return;
    }
    // Increment attendance count by 1
    student->attendance++;
    printf("Attendance marked. Total attendance: %d\n", student->attendance);
}

// Function to collect fee from a student
void collectFee() {
    if (head == NULL) {
        // No students to collect fee from
        printf("No students to collect fees from.\n");
        return;
    }
    int id;
    float fee;
    printf("Enter Student ID to collect fee: ");
    scanf("%d", &id);

    // Find student by ID
    Student* student = findStudent(id);
    if (student == NULL) {
        printf("Student not found.\n");
        return;
    }
    printf("Enter fee amount to collect: ");
    scanf("%f", &fee);

    // Validate fee amount
    if (fee < 0) {
        printf("Invalid amount.\n");
        return;
    }
    // Add fee amount to student's total feesPaid
    student->feesPaid += fee;
    printf("Fee collected. Total fee paid: %.2f\n", student->feesPaid);
}

// Function to display all student records
void viewStudents() {
    if (head == NULL) {
        printf("No students to display.\n");
        return;
    }
    Student* current = head;
    printf("\nID\tName\t\tAttendance\tFees Paid\n");
    printf("-------------------------------------------------\n");
    
    // Traverse the linked list printing each student's details
    while (current != NULL) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", current->id, current->name, current->attendance, current->feesPaid);
        current = current->next;
    }
}

// Function to generate and display report summary
void generateReport() {
    if (head == NULL) {
        printf("No students to generate report for.\n");
        return;
    }
    int totalStudents = 0;
    int totalAttendance = 0;
    float totalFees = 0.0;
    Student* current = head;
    
    // Traverse list to aggregate totals
    while (current != NULL) {
        totalStudents++;
        totalAttendance += current->attendance;
        totalFees += current->feesPaid;
        current = current->next;
    }
    // Print summary report
    printf("\nReport Summary:\n");
    printf("Total Students: %d\n", totalStudents);
    printf("Total Attendance Days: %d\n", totalAttendance);
    printf("Total Fees Collected: %.2f\n", totalFees);
}

// Function to undo the last student entry added
void undoLastEntry() {
    if (lastAdded == NULL) {
        // No recent addition to undo
        printf("No last entry to undo.\n");
        return;
    }
    if (head == NULL) {
        // No students in list
        printf("No students in record.\n");
        return;
    }
    if (head == lastAdded) {
        // If lastAdded student is at head, remove the node from list
        Student* temp = head;
        head = head->next;
        free(temp);          // Free memory allocated for lastAdded
        lastAdded = NULL;    // Reset lastAdded as it is undone
        printf("Last student entry undone successfully.\n");
    } else {
        // Undo only supported for the most recently added student at the head
        printf("Undo is only supported for the most recently added student.\n");
    }
}