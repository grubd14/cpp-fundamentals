#include <iostream>

using namespace std;

class Counter {
public:
  int count;
  Counter(int c) {
    count = c;
  }
  friend Counter operator++(Counter C);
};

Counter operator++(Counter c) {
  c.count++;
  return Counter(c.count);
}

int main() {
  Counter c(4);

  Counter final = ++c;
  cout << final.count;
}
