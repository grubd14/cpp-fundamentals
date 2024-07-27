//A program to demonstrate basic to user defined 
//
#include <iostream>

using namespace std;

class Student {
public:
  int age;
  Student(int age) {
    this -> age = age;
  }

  void display() {
    cout << "Student is " << age << " years old.\n";
  }
};

int main() {
  Student s = 20;
  s.display();
}
