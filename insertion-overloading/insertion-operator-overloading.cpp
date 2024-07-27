//A program to demonstrate insertion operator overloading

#include <iostream>

using namespace std;

class Student {
public:
  string name;
  int age;
  Student (string n, int a) {
    name = n;
    age = a;
  }
  friend ostream& operator<<(ostream& o, Student& s);

};

ostream& operator<<(ostream& o, Student& s) {
  o << "Name = " << s.name << endl;
  o << "Age = " << s.age << endl;
  return o;
}

int main() {
  cout << "Hello world" << endl;
  Student s1("John", 30);

  cout << s1 << endl;
}
