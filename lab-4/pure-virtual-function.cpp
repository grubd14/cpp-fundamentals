//A program to create pure virtual functions from the base class Vehicle and withderived class Motorcycle and Car
//

#include <iostream>

using namespace std;

class Vehicle {
public:
  virtual void start() = 0;
};

class Motorcycle : public Vehicle {
public:
  void start() {
    cout << "This is Motorcycle starting! " << endl;
  }
};

class Car : public Vehicle {
  public:
  void start() {
    cout << "This is Car starting!" << endl;
  }
};

int main() {
  Motorcycle motorcycle1;
  Car car1;

  motorcycle1.start();
  car1.start();
}

