// A program to demosntrate extraction operator overloading 
//

#include <iostream>

using namespace std;

class Stduent {
public:
  string name;
  int age;
  friend istream& operator>>(istream& i, Student& s);
};

istream& operator>>(istream& i, Student& s) {
  cout << "Enter name " << endl;
  i >> s.name;
  cout << "Enter age" << endl;
  i >> s.age;
  return i;
}

int main() {
  Student s;

  cin >> s;

  cout << "Name = " << s.name << endl;
  cout << "Age = " << s.age << endl;
}
