// a program to accept an email address and throw exception if it does not 
// contain @ symbol
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
  for (int i = 0; i< 2; i++) {
    try {
      string email;
      cout << "Enter Email ID: ";
      cin >> email;
      bool emailValid = false;
      for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
          emailValid = true;
          break;
        }
      }
      if(!emailValid) {
        throw runtime_error("Invalid Email ID!!!");
      }
      cout << "Email ID is valid" << endl;

    } catch (runtime_error e) {
      cout << "Exception Caught " << endl << e.what() << endl;
    }
  }
  return 0;
}
