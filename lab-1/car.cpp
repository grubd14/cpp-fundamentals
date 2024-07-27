//A program with Car class with speed, cc, color data members and start, stop,
//accelerate as member functions
//

#include <iostream>

using namespace std;

class Car {
private:
  double carSpeed;
  int carCC;
  string carColor;

public:
  void start() {
    cout << "Car is started" << endl;
  };

  void stop() {
    cout << "Car is stopped" << endl;
  };

  void accelerate() {
    cout << "Car is accelerating" << endl;
  }
};

int main() {
  Car c;
  c.start();
}
