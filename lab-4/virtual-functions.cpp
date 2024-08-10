// A program to demonstrate the concept of polymosrphism with virtual function
// base class Shape and Rectangle Circle with their own implementation of 
// area()
//

#include <iostream>

using namespace std;

class Shape {
public:
  virtual void area() {
    cout << "Base function" << endl;
  }
};

class Rectangle: public Shape {
public:
  void area() {
    cout << "Derived function";
  }
};

class Circle : public Shape {
public:
  void area() {
    cout << "Derived function";
  }
};

int main() {

  Shape *circle = new Circle();
  Shape *rectangle = new Rectangle();

  cout << "Area: " << circle -> area() << endl;

}
