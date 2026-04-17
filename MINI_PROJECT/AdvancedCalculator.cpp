#include <iostream>
#include <cmath>
using namespace std;

int main(){
    char cont = 'y';
    double ans = 0;

    while (true)
    {
        char op;
        double num1, num2;

        if (cont == 'y' || cont == 'Y') {
            cout << "Enter operator (+, -, *, /, ^, %): " << endl;
            cin >> op;
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
        } else if (cont == 'c' || cont == 'C') {
            num1 = ans;
            cout << "Enter operator (+, -, *, /, ^, %): " << endl;
            cin >> op;
            cout << "Enter another number: ";
            cin >> num2;
        }

        switch(op) {
            case '+': ans = num1 + num2; break;
            case '-': ans = num1 - num2; break;
            case '*': ans = num1 * num2; break;
            case '/':
                if(num2 != 0) ans = num1 / num2;
                else cout << "Error: Division by zero!" << endl;
                break;
            case '^': ans = pow(num1, num2); break;
            case '%':
                if(num2 != 0) ans = fmod(num1, num2);
                else cout << "Error: Division by zero!" << endl;
                break;
            default:
                cout << "Error: Invalid operator!" << endl;
        }

        cout << "Result: " << ans << endl;

        cout << "Do you want to continue or perform another calculation? (c/y/n): ";
        cin >> cont;

        if ((cont != 'y' && cont != 'Y') && (cont != 'c' && cont != 'C')) {
            break;
        }
    }

    return 0;
}