#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string customerID;
    string IFSC;
    long long accountNumber;
    double balance;

public:
    BankAccount() {} //A default constructor is needed for map

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
        cout << "Current Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
            cout << "Remaining Balance: " << balance << endl;
        }
    }

    void displayDetails() const {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "IFSC: " << IFSC << endl;
    }
};

void displayMenu(){
    cout << "\nMenu:\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Display Account Details\n";
    cout << "5. Exit\n";
}

int main() {
    cout << fixed << setprecision(2);

    map<long long, BankAccount> accounts;
    int choice;

    do {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                string name, id, ifsc;
                long long accNum;
                double balance;

                cout << "Enter Name: ";
                getline(cin >> ws, name); // To handle spaces in name
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter IFSC: ";
                cin >> ifsc;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Initial Balance: ";
                cin >> balance;

                if (accounts.find(accNum) != accounts.end()) {
                    cout << "Account already exists.\n";
                } else {
                    accounts[accNum] = BankAccount(name, id, ifsc, accNum, balance);
                    cout << "Account created successfully.\n";
                }
                break;
            }

            case 2: {
                long long accNum;
                double amount;

                cout << "Enter Account Number: ";
                cin >> accNum;

                if (accounts.find(accNum) != accounts.end()) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[accNum].deposit(amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 3: {
                long long accNum;
                double amount;

                cout << "Enter Account Number: ";
                cin >> accNum;

                if (accounts.find(accNum) != accounts.end()) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[accNum].withdraw(amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 4: {
                long long accNum;

                cout << "Enter Account Number: ";
                cin >> accNum;

                if (accounts.find(accNum) != accounts.end()) {
                    accounts[accNum].displayDetails();
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 5);

    return 0;
}