//A program to calculate the area of rectangle, triangle and circle
//using constructor overloading 
//

#include <iostream>

using namespace std;

class Area {
private:
  double width;
  double height;
  double radius;
  double pi = 3.14;

public: 
  Area (double w, double h) {
    width = w;
    height = h;
  };

  Area (double r) {
    radius = r;
  };

  int getArea() {
    return width * height;
  }

  double getTriangleArea() {
    return  0.5 *(width * height);
  }

  double getCircleArea() {
    return (pi * radius  * radius); 
  }
};

int main() {
  Area rectangle(23,45); 
  Area triangle(2, 3);
  Area circle(23);

  cout << "Area of rectangle = " << rectangle.getArea() << endl; 
  cout << "Area of triangle= " << triangle.getTriangleArea() << endl;
  cout << "Area of circle = " << circle.getCircleArea() << endl;
}
