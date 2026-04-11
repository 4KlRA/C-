#include <iostream>
using namespace std;

void helloworld(){
    //Hello World program
    cout<<"Hello World!"<<endl;
}

int sum(int a, int b){
    //Sum of two numbers
    return a+b;
}

int factorial(int n){
    //Factorial
    int fact = 1;
    while(n>1){
        fact *=n;
        n--;
    }
    return fact;
}

void fibonacci(int n){
    //Fibonacci sequence
    int f1 = 0, f2 = 1;
    cout << "Fibonacci: " << f1 << " " << f2 << " ";
    for(int i = 2; i < n; i++){
        int temp = f1 + f2;
        cout << temp << " ";
        f1 = f2;
        f2 = temp;
    }
    cout << endl;
}

bool isPrime(int n){
    //Prime number checker
    bool isPrime = true;
    for(int i=2; i*i<=n; i++){
        if (n%i==0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main(){
    helloworld();
    int a, b;
    cout << "Enter two numbers for sum: ";
    cin >> a >> b;
    cout << "Sum = " << sum(a, b) << endl;

    cout << "Enter a number for factorial: ";
    cin >> a;
    cout << "Factorial of " << a << " = " << factorial(a) << endl;

    cout << "Enter number of terms for Fibonacci: ";
    cin >> a;
    fibonacci(a);

    cout << "Enter a number to check if prime: ";
    cin >> a;
    if(isPrime(a))
        cout << a << " is Prime" << endl;
    else
        cout << a << " is Not Prime" << endl;

    return 0;
}