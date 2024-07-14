//A program to display binary operator with member functions

#include <iostream>

using namespace std;

class Student {
public:
  int age;
  Student(int a ) {
    age = a;
  }
  Student operator+(Student s) {
    int totalAge = age + s.age;
    return Student(totalAge);

  }
};

int main() {
  Student s1(20),s2(32);

  Student s3 = s1 + s2;

  int totalAge = s3.age;

  cout << "Total Age =" << totalAge << endl;
}
