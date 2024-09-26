//WAP to append content in the file named demo.txt 
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("demo.txt", ios::app);
    file << "Appending new content to the file.\n";
    file.close();
    cout << "Content appended to demo.txt." << endl;
    return 0;
}
