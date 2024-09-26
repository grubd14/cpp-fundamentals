// WAP to delete reord of Sita from file student_records.txt and display remaining rows
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream infile("student_records.txt");
    ofstream outfile("temp.txt");
    string line;
    while (getline(infile, line)) {
        if (line.find("Sita") == string::npos) {
            outfile << line << endl;  // Copy all lines except Sita's
        }
    }
    infile.close();
    outfile.close();
    remove("student_records.txt");
    rename("temp.txt", "student_records.txt");
    
    // Display remaining rows
    ifstream result("student_records.txt");
    while (getline(result, line)) {
        cout << line << endl;
    }
    result.close();
    return 0;
}

