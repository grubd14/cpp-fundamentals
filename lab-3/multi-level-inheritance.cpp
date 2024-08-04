
#include <iostream>
using namespace std;

// Base class
class Student {
protected:
    int marks1, marks2, marks3;
public:
    void getMarks() {
        cout << "Enter marks for subject 1: ";
        cin >> marks1;
        cout << "Enter marks for subject 2: ";
        cin >> marks2;
        cout << "Enter marks for subject 3: ";
        cin >> marks3;
    }
};

// Derived class from Student
class TotalMarks : public Student {
protected:
    int total;
public:
    void calculateTotal() {
        total = marks1 + marks2 + marks3;
    }
};

// Derived class from TotalMarks
class Percentage : public TotalMarks {
public:
    void displayPercentage() {
        calculateTotal(); // Ensure total marks are calculated
        float percentage = (total / 3.0);
        cout << "Total marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Percentage student; // Creating an object of the derived class
    student.getMarks(); // Calling the base class function to get marks
    student.displayPercentage(); // Calling the derived class function to display percentage
    return 0;
}
