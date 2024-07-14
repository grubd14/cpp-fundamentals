#include <iostream>

using namespace std;

class Bank {
private:
  string depositor_name;
  string account_number;
  string account_type;
  double account_balance;

public:
  void setInitialValues(string dn, string an, string at, double ab) {
    this -> depositor_name = dn;
    this -> account_number = an;
    this -> account_type = at;
    this -> account_balance = ab;

  }

  void depositAmount() {
    double amount;
    cout << "Enter amount to deposit\n";
    cin >> amount;
    cout << "Depending amount Rs " << amount << endl;
    this -> account_balance += amount;
    checkBalance();

  }

  void checkBalance() {
    cout << "Current Balance: " << account_balance << endl;
  }

  void withdrawAmount() {
    double amount;
    cout << "Enter amount to withdraw \n";
    cin >> amount;
    if (amount > account_balance || account_balance == 0) {
      cout << "Insufficient balance" << endl;
    } else {
      cout << "Withdrawing balance Rs " << amount << endl;
      this -> account_balance -= amount;
      checkBalance();
    }
  }
  void displayAccountDetails() {
    cout << ".............Account Details................";
    cout << "Account Name : "<< depositor_name << endl;
    cout << "Account number: " << account_number << endl;
    cout << "Account balance :" << account_balance << endl;

  };

  int main() {
    Bank b;
    b.setInitialValues("Ram", "A1003B455", "SAVING", 8000.0);
    b.depositAmount();
    b.withdrawAmount();
    b.withdrawAmount();
    b.displayAccountDetails();
    return 0;
  }
};
