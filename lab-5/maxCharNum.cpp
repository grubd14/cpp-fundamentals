#include <cstring>
#include <iostream>
#include <string>

using namespace std;

// General template for numeric types
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Specialization for character types
template <>
char maximum<char>(char a, char b) {
    return (toupper(a) > toupper(b)) ? a : b;
}

// Overload for C-style strings
const char* maximum(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    // Test with integers
    cout << "Max of 10 and 15: " << maximum(10, 15) << endl;

    // Test with doubles
    cout << "Max of 3.14 and 2.718: " << maximum(3.14, 2.718) << endl;

    // Test with characters (case-insensitive)
    cout << "Max of 'a' and 'B': " << maximum('a', 'B') << endl;

    // Test with C-style strings
    cout << "Max of \"hello\" and \"world\": " << maximum("hello", "world") << endl;

    // Test with C++ strings
    string str1 = "apple";
    string str2 = "banana";
    cout << "Max of \"" << str1 << "\" and \"" << str2 << "\": " << maximum(str1, str2) << endl;

    return 0;
}
