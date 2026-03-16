#include <iostream>
using namespace std;

int main(){
    //Hello World program
    cout<<"Hello World!"<<endl;
    //Sum of two numbers
    int a = 10, b= 5;
    int sum = a+b;
    cout << "Sum = " << sum << endl;
    //Factorial
    int n = a;
    int fact = 1;
    while(n>1){
        fact *=n;
        n--;
    }
    cout << "Factorial of " << a << " = " << fact << endl;
    //Fibonacci sequence
    int f1 = 0, f2 = 1;
    cout << "Fibonacci: " << f1 << " " << f2 << " ";
    for(int i = 2; i < a; i++){
        int temp = f1 + f2;
        cout << temp << " ";
        f1 = f2;
        f2 = temp;
    }
    cout << endl;
    //Prime number checker
    bool isPrime = true;
    for(int i=2; i*i<=a; i++){
        if (a%i==0){
            isPrime = false;
            break;
        }
    }
    if(isPrime)
        cout << a << " is Prime" << endl;
    else
        cout << a << " is Not Prime" << endl;

    return 0;
}