//A program with Student class, student_name, student_roll, student_age and 
//getName(), setAge(), getRoll(), setRoll(), displayDetails()

#include <iostream>

using namespace std;

class Student {
private:
  string student_name;
  int student_roll;
  int student_age;
public:
  void setName() {
    cout << "Enter the name of student: ";
    cin >> student_name ;
  }

  void getRoll() {
    cout << "Enter the roll no of student: ";
    cin >> student_roll;
  }

  void getAge() {
    cout << "Enter the age of student: ";
    cin >> student_age;
  }
  void getName() {
    cout << "Student Name: " << student_name << endl;
  }

  void getRoll() {
    cout << "Student Roll: " << student_roll << endl;
  }

  void getAge() {
    cout << "Student Age: " << student_age << endl;
  }

  void displayDetails() {
    cout << "Name : " << student_name << endl;
    cout << "Roll No: " << student_roll << endl;
    cout << "Age: " << student_age << endl;
  }
};

int main() {
  Student s1;
  s1.setName();
  s1.getRoll();
  s1.getAge();
  s1.getName();
  s1.getRoll();
  s1.getAge();
  s1.displayDetails();

}
