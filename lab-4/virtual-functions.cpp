// A program to demonstrate the concept of polymosrphism with virtual function
// base class Shape and Rectangle Circle with their own implementation of 
// area()
//

#include <iostream>

using namespace std;

class Shape {
public:
  double length;
  double breadth;
  double radius;
  virtual void area() {
    cout << "Base function" << endl;
  }
};

class Rectangle: public Shape {
public:
  void area() {
    cout << "Enter the length: ";
    cin >> length;
    cout << "Enter the breadth: ";
    cin >> breadth;
    double result;
    result = length * breadth;
    cout << "Area: " << result << endl;
  }
};

class Circle : public Shape {
public:
  void area() {
    const double pi = 3.14159;
    cout << "Enter the radius: ";
    cin >> radius;
    double result;
    result = pi * radius * radius;
    cout << "Area: " << result << endl;

  }
};

int main() {
  Rectangle rectangle1;
  Circle circle1;

  Shape* shape1 = &rectangle1;
  Shape* shape2 = &circle1;

  shape1 -> area();
  shape2 -> area();

}
