//Write a program to create file named student_records.txt and insert contents to it content:    
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("student_records.txt");
    file << "1 Ram 30\n2 Shyam 29\n3 Sita 25" << endl;
    file.close();
    cout << "File created and content added." << endl;
    return 0;
}
