#include <iostream>

using namespace std;

class Bank {
private:
    string depositor_name;
    string account_number;
    double account_balance;
    static string account_type;

public:
    void setInitialValues(string dn, string an, double ab) {
        this->depositor_name = dn;
        this->account_number = an;
        this->account_balance = ab;
    }

    void depositAmount() {
        double amount;
        cout << "Enter amount to deposit\n";
        cin >> amount;
        cout << "Depositing amount Rs " << amount << endl;
        this->account_balance += amount;
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
            this->account_balance -= amount;
            checkBalance();
        }
    }

    friend void displayAccountDetails(Bank &b);
};

string Bank::account_type = "SAVING";

void displayAccountDetails(Bank &b) {
    cout << ".............Account Details................" << endl;
    cout << "Account Name: " << b.depositor_name << endl;
    cout << "Account Number: " << b.account_number << endl;
    cout << "Account Type: " << Bank::account_type << endl;
    cout << "Account Balance: " << b.account_balance << endl;
}

int main() {
    Bank b;
    b.setInitialValues("Ram", "A1003B455", 8000.0);
    b.depositAmount();
    b.withdrawAmount();
    b.withdrawAmount();
    displayAccountDetails(b);
    return 0;
}
