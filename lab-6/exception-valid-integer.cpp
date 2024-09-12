//ensure the input is valid integer with Exception handling 

#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;
int main() {
  while (true) {
    int number;
    bool validInput = false;

    while (!validInput) {
      try {
        cout << "Please enter an integer: ";
        if (!(cin >> number)) {
          throw runtime_error("Invalid input. Please enter a valid integer.");
        }
        validInput = true;
      } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } 
    }
    cout << "You entered: " << number << endl;
    char choice;
    cout << "Would you like to enter another number? (y/n): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice != 'y' && choice != 'Y') {
      cout << "Exiting program." << endl;
      break;
    } }
  return 0;
}
