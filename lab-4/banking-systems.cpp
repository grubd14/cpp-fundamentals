//A program to create a simple banking system with base class and derived 
//classes SavingAccount and CheckingAccount. Use virtual functions to perform
//operations like deposit, withdrawl, and interest calculation.

#include <iostream>

using namespace std;

class Account {
public:
  string account_num = "BAF23554671";
  double account_amount = 21000.43;

  virtual void deposit() {
    cout << "Money is being deposited!";
  };

  virtual void withdraw() {
    cout << "Money is being withdrawn!";
  }

};

class SavingsAccount : public Account {
public:
  void deposit() override {
    cout << "Overidden function of deposit to savings class";
  }
};

class CheckingAccount : public Account {
public:
  void withdraw() override {
    cout << "Overriden function of withdrawn from checking class";
  }

};


int main() {
  CheckingAccount ca1;
  ca1.withdraw();

}

