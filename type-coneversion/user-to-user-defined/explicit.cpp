//A program to demonstrate the conversion of user defined to user defined 
//in an explicit way
//

#include <iostream>

using namespace std;

class Centimeter {
public: 
  int length;
  Centimeter(int l) {
    length = l;
  }
};

class Meter {
public:
  int length;
  Meter(int l) {
    length = l;
  }
  operator Centimeter() {
    return Centimeter (length);
  }
};

int main() {
  Meter m(30);
  Centimeter c = m;
  cout << "length= " << c.length << endl;
}
