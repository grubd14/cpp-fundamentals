//A program to display unary operator overloading using member function 

#include <iostream>

using namespace std;

class Counter {
public:
  int count;

  Counter (int c ) {
    count = c;
  } 
  Counter operator++() {
    count++;
    return Counter(count);
  } 
};

int main() {
  Counter c(4);

  ++c;
  cout << c.count;
}
