//A program to find the area of circle usign class 
//and also taking the user input for radius
//

#include <iostream>

using namespace std;

class Circle {
  double pi = 3.14;
  double radius;

public:
  Circle () {
  };

  void getInput() {
    cout << "Enter the radius of circle: ";
    cin >> radius;
  }

  void getAreaCircle() {
    double totalArea = pi * radius * radius;
    cout << "total area: " << totalArea << endl;
  }
};

int main() {
  Circle c1;
  c1.getInput();
  c1.getAreaCircle();
}
