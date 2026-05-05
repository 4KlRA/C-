#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <limits>
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
    int transactionCount = 0;

public:
    BankAccount() {} //A default constructor is needed for map

    BankAccount(string name, string id, string ifsc, long long accNum, double initialBalance) {
        accountHolderName = name;
        customerID = id;
        IFSC = ifsc;
        accountNumber = accNum;
        balance = (initialBalance >= 0) ? initialBalance : 0;
        transactionHistory.push_back({ "Initial Deposit", initialBalance, balance });
        transactionCount++;
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
        transactionCount++;
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
            transactionCount++;
        }
    }

    void displayDetails() const {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "IFSC: " << IFSC << endl;
        cout << "Transaction Count: " << transactionCount << endl;
    }

    const vector<Transaction>& getTransactionHistory() const {
        return transactionHistory;
    }

    int getTransactionCount() const {
        return transactionCount;
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
            cout << "Account created successfully.\n";
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
            cout << "\nTransaction History for Account " << accNum << "\n";
            cout << string(50, '=') << endl;

            cout << left << setw(20) << "Type" << right << setw(12) << "Amount" << right << setw(12) << "Balance" << endl;

            cout << string(50, '-') << endl;

            for (const Transaction& tx : history) {
                cout << left << setw(20) << tx.type << right << setw(12) << tx.amount << right << setw(12) << tx.balance << endl;
            }
            cout << history.size() << " transactions displayed.\n";
        } else {
            cout << "Account not found.\n";
        }
    }
};

long long getAccountNumber() {
    long long accNum;
    cout << "Enter Account Number: ";
    
    while (!(cin >> accNum)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a valid account number: ";
    }
    return accNum;
}

void displayMenu() {
    cout << "\n====================================\n";
    cout << "           BANK MENU\n";
    cout << "====================================\n";
    cout << "1. Create Account\n";
    cout << "2. Account Operations\n";
    cout << "3. Exit\n";
    cout << "====================================\n";
}

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void accountMenu(BankSystem& bank) {
    long long accNum = getAccountNumber();

    if(bank.accounts.find(accNum) == bank.accounts.end()) {
        cout << "Account not found.\n";
        return;
    }
    int choice;
    do {
        cout << "\n--- Account Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Details\n";
        cout << "4. Transaction History\n";
        cout << "5. Back\n";
        cout << "Choice: ";

        cin >> choice;

        switch (choice) {
            case 1: bank.deposit(accNum); break;
            case 2: bank.withdraw(accNum); break;
            case 3: bank.displayAccountDetails(accNum); break;
            case 4: bank.displayTransactionHistory(accNum); break;
            case 5: return;
            default: cout << "Invalid choice\n";
        }

        pause();
    } while (true);
}

int main() {
    cout << fixed << setprecision(2);

    BankSystem bank;
    int choice;

    do {
        displayMenu();
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch(choice) {

            case 1: {
                bank.createAccount();
                pause();
                break;
            }

            case 2: {
                accountMenu(bank);
                break;
            }

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 3);

    return 0;
}