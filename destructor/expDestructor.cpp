//A simple program to demonstrate destructor 
//

#include <iostream>

using namespace std;

class Destructor {
public:
  Destructor() {
    cout << "Constructor invoked!" << endl;
  }

  ~Destructor() {
  cout << "Destructor executed!" << endl;
}
};

int main() {
  Destructor d1;
  return 0;
}
