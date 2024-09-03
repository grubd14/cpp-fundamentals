// A program to demonstrate the use  addition of multiple types of  data using generic or template functions

#include <iostream>

using namespace std;

// Base case for the template recursion
template<typename T>
T add(T value) {
    return value;
}

// Variadic template for adding multiple values
template<typename T, typename... Args>
T add(T first, Args... args) {
    return first + add(args...);
}

int main() {
    // Adding integers
    cout << "Sum of integers (1, 2, 3, 4, 5): " 
         << add(1, 2, 3, 4, 5) << endl;

    // Adding floating-point numbers
    cout << "Sum of doubles (1.1, 2.2, 3.3, 4.4): " 
         << add(1.1, 2.2, 3.3, 4.4) << endl;

    // Adding mixed types (will use type of first argument)
    cout << "Sum of mixed types (int first: 1, 2.2, 3, 4.4, 5): " 
         << add(1, 2.2, 3, 4.4, 5) << endl;

    // Adding mixed types (will use type of first argument)
    cout << "Sum of mixed types (double first: 1.0, 2, 3.3, 4, 5.5): " 
         << add(1.0, 2, 3.3, 4, 5.5) << endl;

    // Using long integers
    cout << "Sum of long integers (1000000, 2000000, 3000000): " 
         << add(1000000L, 2000000L, 3000000L) << endl;

    return 0;
}
