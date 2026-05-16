#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <ctime>
using namespace std;

struct Transaction {
    string type;
    long long amount, balance;
    time_t timestamp;
};

time_t getCurrentTime() {
    time_t now = time(0);
    return now;
}

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

class BankAccount {
private:
    string accountHolderName;
    string customerID;
    string IFSC;
    long long accountNumber;
    long long balance; //Stored in paisa to avoid floating point issues
    vector <Transaction> transactionHistory;
    int PIN;

public:
    BankAccount() {} //A default constructor is needed for map

    BankAccount(string name, string id, string ifsc, long long accNum, long long initialBalance, int pin) {
        accountHolderName = name;
        customerID = id;
        IFSC = ifsc;
        PIN = pin;
        accountNumber = accNum;
        balance = (initialBalance >= 0) ? initialBalance : 0;
        transactionHistory.push_back({ "Account Opened", balance, balance, getCurrentTime() });
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

    void deposit(long long amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        } 
        balance += amount;
        cout << "Deposit successful.\n";
        cout << "Current Balance (in paisa): " << balance << endl;
        transactionHistory.push_back({ "Deposit", amount, balance, getCurrentTime() });
    }

    void withdraw(long long amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
            cout << "Remaining Balance (in paisa): " << balance << endl;
            transactionHistory.push_back({ "Withdrawal", amount, balance, getCurrentTime() });
        }
    }

    void displayDetails() {
        cout << "\n====================================\n";
        cout << "       ACCOUNT DETAILS\n";
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance (in paisa): " << balance << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "IFSC: " << IFSC << endl;
        cout << "Transaction Count: " << transactionHistory.size() << endl;
        cout << "====================================\n";
    }

    const vector<Transaction>& getTransactionHistory() const {
        return transactionHistory;
    }

    void saveToFile(ofstream& out) {
        out << accountHolderName << endl;
        out << customerID << endl;
        out << IFSC << endl;
        out << accountNumber << endl;
        out << balance << endl;
        out << PIN << endl;
        out << transactionHistory.size() << endl;
        for(const Transaction& tx: transactionHistory) {
            out << tx.type << endl;
            out << tx.amount << endl;
            out << tx.balance << endl;
            out << tx.timestamp << endl;
        }
    }

    static BankAccount loadFromFile(ifstream& in) {
        BankAccount account;
        getline(in, account.accountHolderName);
        getline(in, account.customerID);
        getline(in, account.IFSC);
        in >> account.accountNumber;
        in >> account.balance;
        in >> account.PIN;
        int txCount;
        in >> txCount;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        for(size_t i = 0; i < txCount; i++) {
            Transaction tx;
            getline(in, tx.type);
            in >> tx.amount;
            in >> tx.balance;
            in >> tx.timestamp;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            account.transactionHistory.push_back(tx);
        }
        return account;
    }

    long long getStoredAccountNumber() const {
        return accountNumber;
    }

    string getCustomerID() const {
        return customerID;
    }
};

class BankSystem {
private:
    map<long long, BankAccount> accounts;
    long long loadLastAccountNumber();
    void saveLastAccountNumber(long long number);
    vector<long long> deleteAccountNumbers;
    void saveAccounts();
    void loadAccounts();

public:

    BankSystem() {
        loadAccounts();
    }

    long long uniqueAccountNumber() {
        if(!deleteAccountNumbers.empty()) {
            long long accNum = deleteAccountNumbers.back();
            deleteAccountNumbers.pop_back();
            return accNum;
        }
        static long long lastAccountNumber = loadLastAccountNumber();
        long long newAccountNumber = lastAccountNumber;
        lastAccountNumber++;
        saveLastAccountNumber(lastAccountNumber);
        return newAccountNumber;
    }

    void createAccount() {
        string name, id, ifsc;
        long long accNum;
        long long initialBalance;
        cout << "Enter Name: ";
        getline(cin >> ws, name); // To handle spaces in name
        cout << "Enter Customer ID: ";
        cin >> id;
        cout << "Enter IFSC: ";
        cin >> ifsc;
        accNum = uniqueAccountNumber();
        cout << "Generated Account Number: " << accNum << endl;
        cout << "Enter Initial Balance (in paisa): ";
        while(!(cin >> initialBalance)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid amount. Enter again: ";
        }
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
            long long amount;
            cout << "Enter amount to deposit (in paisa): ";
            while(!(cin >> amount)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount. Enter again: ";
            }
            accounts[accNum].deposit(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdraw(long long accNum) {
        if(accounts.find(accNum) != accounts.end()) {
            long long amount;
            cout << "Enter amount to withdraw (in paisa): ";
            while(!(cin >> amount)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount. Enter again: ";
            }
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
            cout << string(100, '=') << endl;

            cout << left << setw(20) << "Type" << right << setw(20) << "Amount (in paisa)" << right << setw(20) << "Balance (in paisa)" << right << setw(30) << "Timestamp" << endl;

            cout << string(100, '-') << endl;

            for (const Transaction& tx : history) {
                cout << left << setw(20) << tx.type << right << setw(20) << tx.amount << right << setw(20) << tx.balance << right << setw(30) << ctime(&tx.timestamp) << endl;
            }
            cout << history.size() << " transactions displayed.\n";
        } else {
            cout << "Account not found.\n";
        }
    }

    void deleteAccount(long long accNum) {
        if(accountExists(accNum)) {
            if(verifyAccountPIN(accNum)) {
                deleteAccountNumbers.push_back(accNum);
                accounts.erase(accNum);
                cout << "Account deleted successfully.\n";
            } else {
                cout << "PIN verification failed. Account not deleted.\n";
            }
        } else {
            cout << "Account not found.\n";
        }
    }

    void transfer(long long fromAccNum) {
        long long toAccNum;
        long long amount;
        cout << "Enter the account number to transfer to: ";
        cin >> toAccNum;
        cout << "Enter the amount to transfer (in paisa): ";
        cin >> amount;
        if(!accountExists(fromAccNum)) {
            cout  << "Source account not found.\n";
            return;
        }
        if(!accountExists(toAccNum)) {
            cout << "Destination account not found.\n";
            return;
        }
        long long prevBalance = accounts[fromAccNum].getTransactionHistory().back().balance;
        accounts[fromAccNum].withdraw(amount);
        if(accounts[fromAccNum].getTransactionHistory().back().balance == prevBalance) {
            cout << "Transfer failed.\n";
            return;
        }
        accounts[toAccNum].deposit(amount);
        cout << "Transfer successful.\n";
    }

    void searchByCustomerID() {
    string id;
    cout << "Enter Customer ID: ";
    cin >> id;
    bool found = false;
    for(auto& pair : accounts) {
        if(pair.second.getCustomerID() == id) {
            pair.second.displayDetails();
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "No account found with Customer ID: " << id << endl;
    }
}

    ~BankSystem() {
        saveAccounts();
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

void BankSystem::saveAccounts() {
    ofstream out("accounts.txt");
    out << accounts.size() << endl;
    for(auto& pair : accounts) {
        pair.second.saveToFile(out);
    }
    out << deleteAccountNumbers.size() << endl;
    for(long long accNum : deleteAccountNumbers) {
        out << accNum << endl;
    }
    out.close();
}

void BankSystem:: loadAccounts() {
    ifstream in("accounts.txt");
    if(!in.is_open()){
        return;
    }
    size_t count;
    in >> count;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    for(size_t i = 0; i < count; i++) {
        BankAccount account = BankAccount::loadFromFile(in);
        accounts[account.getStoredAccountNumber()] = account;
    }
    size_t delCount;
    in >> delCount;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    for(size_t i = 0; i < delCount; i++) {
        long long accNum;
        in >> accNum;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        deleteAccountNumbers.push_back(accNum);
    }
    in.close();
}

void displayMenu() {
    cout << "\n====================================\n";
    cout << "           BANK MENU\n";
    cout << "====================================\n";
    cout << "1. Create Account\n";
    cout << "2. Account Operations\n";
    cout << "3. Search by Customer ID\n";
    cout << "4. Exit\n";
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
        pause();
        return;
    }
    if(!bank.verifyAccountPIN(accNum)) {
        return;
    }
    int choice;
    do {
        cout << "\n--- Account Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer to another account\n";
        cout << "4. View Account Details\n";
        cout << "5. Transaction History\n";
        cout << "6. Change PIN\n";
        cout << "7. Delete Account\n";
        cout << "8. Back\n";
        cout << "Choice: ";

        cin >> choice;

        switch (choice) {
            case 1: bank.deposit(accNum); break;
            case 2: bank.withdraw(accNum); break;
            case 3: bank.transfer(accNum); break;
            case 4: bank.displayAccountDetails(accNum); break;
            case 5: bank.displayTransactionHistory(accNum); break;
            case 6: bank.changeAccountPIN(accNum); break;
            case 7: bank.deleteAccount(accNum); return;
            case 8: return;
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
            case 3: {
                bank.searchByCustomerID();
                pause();
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while(choice != 4);
    return 0;
}