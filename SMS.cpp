#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For std::setprecision

// --- 1. The Class Definition ---
class Student {
private:
    std::string name;
    int id;
    double gpa;

public:
    // Constructor
    Student(std::string n, int i, double g) : name(n), id(i), gpa(g) {}

    // Public method to display student information
    void displayInfo() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "ID: " << id
                  << ", Name: " << name
                  << ", GPA: " << gpa << std::endl;
    }

    // Accessor methods (Getters)
    int getId() const { return id; }
    double getGpa() const { return gpa; }
    std::string getName() const { return name; }
};

// --- 2. Manager Functionality ---
class StudentManager {
private:
    // Store student objects in a vector
    std::vector<Student> students;
    int nextId = 101;

public:
    // Method to add a new student
    void addStudent(const std::string& name, double gpa) {
        Student newStudent(name, nextId++, gpa);
        students.push_back(newStudent);
        std::cout << "✅ Added student " << name << " with ID " << newStudent.getId() << std::endl;
    }

    // Method to display all students
    void displayAllStudents() const {
        if (students.empty()) {
            std::cout << "The system has no students recorded." << std::endl;
            return;
        }
        std::cout << "\n--- All Students in System ---\n";
        for (const auto& student : students) {
            student.displayInfo();
        }
        std::cout << "------------------------------\n";
    }

    // Method to find a student by ID (using a basic algorithm)
    void findStudentById(int searchId) const {
        // Use a range-based for loop to search
        for (const auto& student : students) {
            if (student.getId() == searchId) {
                std::cout << "\n🔎 Student Found:\n";
                student.displayInfo();
                return;
            }
        }
        std::cout << "❌ Student with ID " << searchId << " not found." << std::endl;
    }
};

// --- 3. Main Application Logic ---
int main() {
    StudentManager manager;

    std::cout << "--- Student Management System Demo ---\n";

    // Add students
    manager.addStudent("Alice Johnson", 3.85);
    manager.addStudent("Bob Williams", 3.20);
    manager.addStudent("Charlie Davis", 4.00);

    // Display all students
    manager.displayAllStudents();

    // Search for a student
    manager.findStudentById(102);

    // Search for a student that doesn't exist
    manager.findStudentById(999);

    return 0;
}
