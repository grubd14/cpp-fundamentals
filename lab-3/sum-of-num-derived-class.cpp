//A program to add two numbers using single inheritance
//by accepting the input in base class and display the sum of two numbers
//derived class 


#include <iostream>
using namespace std;

// Base class
class Base {
protected:
    int num1, num2;
public:
    void getNumbers() {
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
    }
};

// Derived class
class Derived : public Base {
public:
    void displaySum() {
        int sum = num1 + num2;
        cout << "The sum of the two numbers is: " << sum << endl;
    }
};

int main() {
    Derived obj;     // Creating an object of the Derived class
    obj.getNumbers(); // Calling the base class function
    obj.displaySum(); // Calling the derived class function
    return 0;
}
