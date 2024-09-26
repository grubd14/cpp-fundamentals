// WAP to reas contents and display in console from the file student_records.txt
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("student_records.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    return 0;
}
