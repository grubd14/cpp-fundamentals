//A program to illustrate the use of binary operator with friend functions

#include <iostream>

using namespace std;

class Student {
  int age;
public:
  Student(int a) {
    age = a;
  };  

  friend bool operator<(Student s1, Student s2);
};

bool operator<(Student s1,Student s2) {
  if (s1.age < s2.age) {
    return true;
  } else {
    return false;
  }
}

int main() {
  Student ram(20), shyam(30);

  if(ram<shyam) {
    cout << "Ram is younger." << endl;
  } else {
    cout << "Shyam is younger" << endl;
  }
}

