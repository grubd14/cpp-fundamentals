//A program to demonstrate the type conversion from user defined to user defined 
//in implicit way

#include <iostream>

using namespace std;

class Meter {
public:
  int length;
  Meter (int l) {
    length = l;
  }
};

class Centimeter {
public: 
  int length;
  Centimeter(Meter m) {
    length = m.length;
  }
};

int main() {
  Meter m(20);
  Centimeter c = m;
  cout << "Length = " << c.length << endl;
}
