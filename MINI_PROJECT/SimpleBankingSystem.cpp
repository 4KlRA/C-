#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

struct Transaction {
    string type;
    double amount, balance;
};

int enterPIN() {
    int pin;
    while (true) {
        cin >> pin;
        if (cin.fail() || pin < 1000 || pin > 9999) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid PIN. Please enter a 4-digit numeric PIN: ";
        } else {
            break;
        }
    }
    return pin;
}

class BankAccount {
private:
    string accountHolderName;
    string customerID;
    string IFSC;
    long long accountNumber;
    double balance;
    vector <Transaction> transactionHistory;
    int PIN;

public:
    BankAccount() {} //A default constructor is needed for map

    BankAccount(string name, string id, string ifsc, long long accNum, double initialBalance, int pin) {
        accountHolderName = name;
        customerID = id;
        IFSC = ifsc;
        PIN = pin;
        accountNumber = accNum;
        balance = (initialBalance >= 0) ? initialBalance : 0;
        transactionHistory.push_back({ "Initial Deposit", initialBalance, balance });
    }

    bool verifyPIN() {
        int enteredPIN;
        int attempts = 0;
        const int maxAttempts = 3;
        while(attempts < maxAttempts) {
            cout << "Enter 4-digit PIN: ";
            enteredPIN = enterPIN();
            if(enteredPIN == PIN) {
                return true;
            }
            attempts++;
            cout << "Incorrect PIN. " << maxAttempts - attempts << " attempts remaining.\n";
        }

        cout << "Too many incorrect attempts. Access denied.\n";

        return false;
    }

    void changePIN() {
        if(verifyPIN()) {
            cout << "Enter new 4-digit PIN: ";
            int newPIN = enterPIN();
            PIN = newPIN;
            cout << "PIN changed successfully.\n";
        } else {
            cout << "PIN verification failed.\n";
        }
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

    void displayDetails() {
        cout << "\n====================================\n";
        cout << "       ACCOUNT DETAILS\n";
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "IFSC: " << IFSC << endl;
        cout << "Transaction Count: " << transactionHistory.size() << endl;
    }

    const vector<Transaction>& getTransactionHistory() const {
        return transactionHistory;
    }

    int getTransactionCount() const {
        return transactionHistory.size();
    }
};

class BankSystem {
private:
    map<long long, BankAccount> accounts;
    long long loadLastAccountNumber();
    void saveLastAccountNumber(long long number);

public:

    long long uniqueAccountNumber() {
        static long long lastAccountNumber = loadLastAccountNumber();
        long long newAccountNumber = lastAccountNumber;
        lastAccountNumber++;
        saveLastAccountNumber(lastAccountNumber);
        return newAccountNumber;
    }

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
        accNum = uniqueAccountNumber();
        cout << "Generated Account Number: " << accNum << endl;
        cout << "Enter Initial Balance: ";
        cin >> initialBalance;
        cout << "Set a 4-digit PIN for your account: ";
        int pin = enterPIN();

        if (accounts.find(accNum) != accounts.end()) {
            cout << "Account already exists.\n";
        } else {
            accounts[accNum] = BankAccount(name, id, ifsc, accNum, initialBalance, pin);
            cout << "Account created successfully.\n";
        }
    }

    bool accountExists(long long accNum) {
        return accounts.find(accNum) != accounts.end();
    }

    bool verifyAccountPIN(long long accNum) {
        if(accountExists(accNum)) {
            return accounts[accNum].verifyPIN();
        } else {
            cout << "Account not found.\n";
            return false;
        }
    }

    bool changeAccountPIN(long long accNum) {
        if(accountExists(accNum)) {
            accounts[accNum].changePIN();
            return true;
        } else {
            cout << "Account not found.\n";
            return false;
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

long long BankSystem::loadLastAccountNumber() {
    ifstream file("account_number.txt");
    long long number;
    if(file >> number) {
        file.close();
        return number;
    }
    file.close();
    return 1000000000;
}

void BankSystem::saveLastAccountNumber(long long number) {
    ofstream file("account_number.txt");
    file << number;
    file.close();
}

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

    if(!bank.accountExists(accNum)) {
        cout << "Account not found.\n";
        return;
    }
    if(!bank.verifyAccountPIN(accNum)) {
        cout << "Invalid PIN.\n";
        return;
    }
    int choice;
    do {
        cout << "\n--- Account Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Details\n";
        cout << "4. Transaction History\n";
        cout << "5. Change PIN\n";
        cout << "6. Back\n";
        cout << "Choice: ";

        cin >> choice;

        switch (choice) {
            case 1: bank.deposit(accNum); break;
            case 2: bank.withdraw(accNum); break;
            case 3: bank.displayAccountDetails(accNum); break;
            case 4: bank.displayTransactionHistory(accNum); break;
            case 5: bank.changeAccountPIN(accNum); break;
            case 6: return;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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