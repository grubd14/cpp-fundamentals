//WAP to modifiy the age of syam from 29 to 22 that is available in file student_records.txt 
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream infile("student_records.txt");
    ofstream outfile("temp.txt");
    string line, name;
    while (getline(infile, line)) {
        if (line.find("Shyam") != string::npos) {
            stringstream ss(line);
            int id, age;
            ss >> id >> name >> age;
            outfile << id << " " << name << " 22\n";  // Modify age to 22
        } else {
            outfile << line << endl;
        }
    }
    infile.close();
    outfile.close();
    remove("student_records.txt");
    rename("temp.txt", "student_records.txt");
    cout << "Age of Shyam modified." << endl;
    return 0;
}
