#include <iostream>
#include <cmath>
using namespace std;

int main(){
    while (true)
    {
        char op, cont = 'y';
        double num1, num2, ans;
        if (cont == 'y' || cont == 'Y') {
            cout << "Enter operator (+, -, *, /, ^, %): ";
            cin >> op;
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
        } else if (cont == 'c' || cont == 'C') {
            num1 = ans;
            cout << "Enter operator (+, -, *, /, ^, %): ";
            cin >> op;
            cout << "Enter another number: ";
            cin >> num2;
        }
        switch(op) {
            case '+':
                ans = num1 + num2;
                break;
            case '-':
                ans = num1 - num2;
                break;
            case '*':
                ans = num1 * num2;
                break;
            case '/':
                if(num2 != 0) {
                    ans = num1 / num2;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case '^':
                ans = pow(num1, num2);
                break;
            case '%':
                if(num2 != 0) {
                    ans = fmod(num1, num2);
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            default:
                cout << "Error: Invalid operator!" << endl;
        }
        cout << "Do you want to continue or perform another calculation? (c/y/n): ";
        cin >> cont;
        if ((cont != 'y' && cont != 'Y') && (cont != 'c' && cont != 'C')) {
            break;
        }
    }
    return 0;
}