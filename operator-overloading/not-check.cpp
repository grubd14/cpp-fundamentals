// A program to demonstrate the overloading of operators 
// create a a person class and !Person checks if person's nationality is Nepali or not

#include <iostream>

using namespace std;

class Person {
public:
  string nationality;
  Person(string n) {
      nationality = n;
  }
  bool operator!() {
    if (nationality! = "Nepali") {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Person P("Nepali");
  if (!Person) {
    cout << "Not a Nepali\n";
  } else {
    cout << "Nepali\n";
  }
}
