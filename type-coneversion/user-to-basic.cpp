//A program to demonstrate user defined to basic type conversion
//

#include <iostream>

using namespace std;

class Student {
public:
  int age;
  Student (int age) {
    this -> age = age;
  }

  operator int() {
    return age;
  }
};

int main() {
  Student s(30);
  int age = s;
  cout << "Age = " << age << endl;
  return 0;
}
