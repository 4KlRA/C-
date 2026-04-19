#include <bits/stdc++.h>
using namespace std;

long long AnyBaseToDec(string num, int base){
    if (base < 2 || base > 36) {
        cout << "Invalid base\n";
        return -1;
    }

    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long decimal = 0;
    bool negative = false;

    int start = 0;
    if(num[0] == '-'){
        negative = true;
        start = 1;
    }

    for(int i = start; i < num.length(); i++){
        char c = toupper(num[i]);
        int value = digits.find(c);

        if (value == string::npos || value >= base) {
            cout << "Invalid number for the given base\n";
            return -1;
        }

        decimal = decimal * base + value;
    }

    return negative ? -decimal : decimal;
}

string DecToAnyBase(long long num, int base){
    if (base < 2 || base > 36) {
        return "Invalid base";
    }

    if (num == 0) return "0";

    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";

    while(num > 0){
        int rem = num % base;
        result = digits[rem] + result;
        num /= base;
    }

    return result;
}

string AnyBaseToAnyBase(string num, int fromBase, int toBase) {
    long long decimal = AnyBaseToDec(num, fromBase);
    if (decimal == -1) {
        return "Conversion failed";
    }

    return DecToAnyBase(decimal, toBase);
}

int main(){
    int choice;
    string num;
    int base, fromBase, toBase;

    cout << "Number System Converter\n";
    cout << "Note: Valid bases are from 2 to 36\n";
    cout << "1. Decimal to any base\n";
    cout << "2. Any base to Decimal\n";
    cout << "3. Any base to any base\n";
    cout << "Choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            cout << "Enter the decimal number: ";
            cin >> num;
            cout << "Enter the base: ";
            cin >> base;
            try {
                bool negative = (num[0] == '-');
                long long n = abs(stoll(num));
                if(!negative) {
                    cout << DecToAnyBase(n, base) << endl;
                } else {
                    cout << "-" << DecToAnyBase(n, base) << endl;
                }
            } catch (...) {
                cout << "Invalid decimal input\n";
            }
            break;

        case 2:
            cout << "Enter the number: ";
            cin >> num;
            cout << "Enter the base: ";
            cin >> base;
            cout << AnyBaseToDec(num, base) << endl;
            break;

        case 3:
            cout << "Enter the number: ";
            cin >> num;
            cout << "Enter the base: ";
            cin >> fromBase;
            cout << "Enter the base to convert to: ";
            cin >> toBase;
            cout << AnyBaseToAnyBase(num, fromBase, toBase) << endl;
            break;

        default:
            cout << "Invalid Choice.\n";
    }
    return 0;
}