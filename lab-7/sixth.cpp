// WAP to read contents from file named demo.txt and print number of characters available in that file.
//


#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("demo.txt");
    char ch;
    int charCount = 0;
    while (file.get(ch)) {
        charCount++;
    }
    file.close();
    cout << "Number of characters in demo.txt: " << charCount << endl;
    return 0;
}

