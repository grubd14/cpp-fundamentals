//A program to calculate perimter and area of rectangle from the user input 
//data using the concept of class 

//this program uses public modifier 
//all the member data and member functions are easily accessible from anywhere 
//and are accesed using dot(.) 
#include <iostream>

using namespace std;

class Rectangle {
public:
  int lengthRec;
  int widthRec;

  void calculatePerimeter() {
    int totalPeri = 2*(lengthRec + widthRec);
    cout << "total perimeter: " << totalPeri << endl;
  }

  void calculateArea() {
    int totalArea = lengthRec * widthRec;
    cout << "total area: " << totalArea << endl;
  }

  void getInputData() {
    cout << "Enter length: " << endl;
    cin >> lengthRec;
    cout << "Enter width: " << endl;
    cin  >> widthRec;

  }
};

int main() {
  Rectangle r1;
  r1.getInputData();
  r1.calculateArea();
  r1.calculatePerimeter();
}
