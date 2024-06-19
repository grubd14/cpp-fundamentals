#include <iostream>

using namespace std;

class BankAccount{
private:
  string  accountNumber;
  double balance;

public:
  void setAccountNumber() {
    string accNumber;
    cout << "Enter the bank account number:\t";
    cin  >> accNumber;
    this-> accountNumber = accNumber;
  }

  void setBalance() {
    double bal;
    cout << "Enter the balance: " << endl;
    cin >>  bal;
    this -> balance = bal;
  }

  string getAccountNumber() {
    cout << "Account Number: " << accountNumber << endl;
    return accountNumber;
  }

  double getBalance() {
   cout << "Current Balance: " << balance << endl;
    return balance;
  }

  void depositAmount() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    cout << "Depositing amount Rs: " << amount << endl;
    this -> balance += amount;
  }

  void withdrawBalance() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > balance || balance == 0) {
      cout << "Insufficient balance" << endl;

    } else {
      cout << "Withdrawing balance Rs: " << amount << endl;
      this -> balance -= amount;
    }
  }
};

int main() {
  BankAccount b;
  b.setAccountNumber();
  b.setBalance();
  b.getAccountNumber();
  b.getBalance();
  b.depositAmount();
  b.withdrawBalance();
  b.getBalance();
  return 0;

}
