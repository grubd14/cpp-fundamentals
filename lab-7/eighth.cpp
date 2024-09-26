//WAP to create two files named file1.txt file2.txt with some text in those files. Also merge the contents of those two files into the file named file3.txt
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file1("file1.txt");
    ofstream file2("file2.txt");
    file1 << "Content of file1.\n";
    file2 << "Content of file2.\n";
    file1.close();
    file2.close();
    
    ifstream infile1("file1.txt");
    ifstream infile2("file2.txt");
    ofstream outfile("file3.txt");
    
    string line;
    while (getline(infile1, line)) {
        outfile << line << endl;
    }
    while (getline(infile2, line)) {
        outfile << line << endl;
    }
    
    infile1.close();
    infile2.close();
    outfile.close();
    
    cout << "Files merged into file3.txt." << endl;
    return 0;
}
