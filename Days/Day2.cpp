#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    //Reverse a number
    int num;
    cout << "Enter a number";
    cin >> num;
    int num1 = num;
    int reverse = 0;
    while(num>0){
        int digit = num%10;
        reverse = reverse*10 + digit;
        num /= 10;
    }
    cout << "Reversed Number =" << reverse << endl;
    //Check palindrome number
    if(num1 == reverse){
        cout << num1 << " is a Palindrome Number" << endl;
    } else {
        cout << num1 << " is not a Palindrome Number" << endl;
    }
    //Find GCD of two numbers
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int gcd = 1;
    for(int i=1; i<=min(a,b); i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }    
    cout << "GCD of " << a << " and " << b << " = " << gcd << endl;
    //Print multiplication table
    int num2;
    cout << "Enter a number for multiplication table: ";
    cin >> num2;
    for(int i = 1; i <=10; i++){
        cout << num2 << " * " << i << " = " << num2*i << endl;
    }
    //Find largest element in an array
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int largest = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    cout << "Largest element in the array is: " << largest << endl;
    return 0;
}