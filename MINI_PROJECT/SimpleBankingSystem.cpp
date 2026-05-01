#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

struct Transaction {
    string type;
    double amount, balance;
};

class BankAccount {
private:
    string accountHolderName;
    string customerID;
    string IFSC;
    long long accountNumber;
    double balance;
    vector <Transaction> transactionHistory;

public:
    BankAccount() {} //A default constructor is needed for map

    BankAccount(string name, string id, string ifsc, long long accNum, double initialBalance) {
        accountHolderName = name;
        customerID = id;
        IFSC = ifsc;
        accountNumber = accNum;
        balance = (initialBalance >= 0) ? initialBalance : 0;
        transactionHistory.push_back({ "Initial Deposit", initialBalance, balance });
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful.\n";
        cout << "Current Balance: " << balance << endl;
        transactionHistory.push_back({ "Deposit", amount, balance });
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
            transactionHistory.push_back({ "Withdrawal", amount, balance });
        }
    }

    void displayDetails() const {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "IFSC: " << IFSC << endl;
    }

    const vector<Transaction>& getTransactionHistory() const {
        return transactionHistory;
    }
};

class BankSystem {
private:
    map<long long, BankAccount> accounts;

public:
    void createAccount() {
        string name, id, ifsc;
        long long accNum;
        double initialBalance;
        cout << "Enter Name: ";
        getline(cin >> ws, name); // To handle spaces in name
        cout << "Enter Customer ID: ";
        cin >> id;
        cout << "Enter IFSC: ";
        cin >> ifsc;
        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        if (accounts.find(accNum) != accounts.end()) {
            cout << "Account already exists.\n";
        } else {
            accounts[accNum] = BankAccount(name, id, ifsc, accNum, initialBalance);
            cout << "Account created succesfully.\n";
        }
    }

    void deposit(long long accNum) {
        if(accounts.find(accNum) != accounts.end()) {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            accounts[accNum].deposit(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdraw(long long accNum) {
        if(accounts.find(accNum) != accounts.end()) {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            accounts[accNum].withdraw(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void displayAccountDetails(long long accNum) {
        if(accounts.find(accNum) != accounts.end()) {
            accounts[accNum].displayDetails();
        } else {
            cout << "Account not found.\n";
        }
    }

    void displayTransactionHistory(long long accNum) {
        if(accounts.find(accNum) != accounts.end()) {
            const vector<Transaction>& history = accounts[accNum].getTransactionHistory();
            cout << "\nTransaction History for Account " << accNum << ":\n\n";
            cout << left << setw(15) << "Type"  << setw(15) << "Amount" << setw(15) << "Balance" << endl;
            cout << string(45, '-') << endl;
            for (const Transaction& tx : history) {
                cout << left << setw(15) << tx.type << setw(15) << tx.amount << setw(15) << tx.balance << endl;
            }
        } else {
            cout << "Account not found.\n";
        }
    }
};

void displayMenu(){
    cout << left << setw(5) << "Menu:\n";
    cout << left << setw(5) << "1." <<  "Create Account\n";
    cout << left << setw(5) << "2." <<  "Deposit\n";
    cout << left << setw(5) << "3." <<  "Withdraw\n";
    cout << left << setw(5) << "4." <<  "Display Account Details\n";
    cout << left << setw(5) << "5." <<  "Display Transaction History\n";
    cout << left << setw(5) << "6." <<  "Exit\n";
}

int main() {
    cout << fixed << setprecision(2);

    BankSystem bank;
    int choice;

    do {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                bank.createAccount();
                break;
            }

            case 2: {
                long long accNum;
                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.deposit(accNum);
                break;
            }

            case 3: {
                long long accNum;
                cout << "Enter Account Number: ";
                cin >> accNum;

                bank.withdraw(accNum);
                break;
            }

            case 4: {
                long long accNum;

                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.displayAccountDetails(accNum);
                break;
            }

            case 5: {
                long long accNum;
                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.displayTransactionHistory(accNum);
                break;
            }

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 6);

    return 0;
}