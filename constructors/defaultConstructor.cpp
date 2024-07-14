//Demonstrate the use of default constructor, parameterized constructor 
// and destructor 


#include <iostream>

using namespace std;

class Student {
private:
  string name;

public:
  Student() {
    cout << "Default contructor called " << endl;

  }

  Student(string name) {
    cout << "Parameterized contructor called" << endl;

  }

  ~Student() {
    cout << "Destructor called " << endl;
  }
};

int main() {
  Student s;
  /* Student s1("Ram"); */
}
