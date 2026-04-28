#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string customerID;
    string IFSC;
    long long accountNumber;
    double balance;

public:
    BankAccount(string name, string id, string ifsc, long long accNum, double initialBalance) {
        accountHolderName = name;
        customerID = id;
        IFSC = ifsc;
        accountNumber = accNum;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }

    void displayDetails() const {
        cout << "\nAccount Holder: " << accountHolderName << endl;   
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    cout << fixed << setprecision(2);
    BankAccount acc("John Doe", "C12345", "IFSC001", 1234567890, 1000.0);
    acc.deposit(500);
    acc.withdraw(200);
    acc.withdraw(2000);
    acc.displayDetails();
    return 0;
}