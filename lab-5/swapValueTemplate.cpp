// a program to swap values of data type using template
#include <iostream>

using namespace std;

template <typename T1, typename T2>
void swapValues(T1& a, T2& b) {
    T1 temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    double y = 10.5;

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swapValues(x, y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
