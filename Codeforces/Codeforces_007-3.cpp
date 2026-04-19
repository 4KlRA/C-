#include <iostream>
using namespace std;

int main(){
    int money;
    cin >> money;
    int left = money % 100;
    int bills = money/100;
    bills += left / 20;
    left = left % 20;
    bills += left / 10;
    left = left % 10;
    bills += left / 5;
    left = left % 5;
    bills += left;
    cout << bills;
}