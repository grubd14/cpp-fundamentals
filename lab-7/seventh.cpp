//WAP to read contents from file named demo.txt and print number of words and number of lines available in that file
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream file("demo.txt");
    string line, word;
    int wordCount = 0, lineCount = 0;
    
    while (getline(file, line)) {
        lineCount++;
        stringstream ss(line);
        while (ss >> word) {
            wordCount++;
        }
    }
    file.close();
    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of words: " << wordCount << endl;
    return 0;
}
