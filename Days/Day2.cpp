#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int reverseNumber(int num){
    //Reverse a number
    int reverse = 0;
    while(num>0){
        int digit = num%10;
        reverse = reverse*10 + digit;
        num /= 10;
    }
    return reverse;
}

bool isPalindrome(int num){
    //Check palindrome number
    if(num == reverseNumber(num)){
        return true;
    } else {
        return false;
    }
}

int gcd(int a, int b){
    //Find GCD of two numbers
    int gcd = 1;
    for(int i=1; i<=min(a,b); i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }    
    return gcd;
}

void multiplicationTable(int num){
    //Print multiplication table
    for(int i = 1; i <=10; i++){
        cout << num << " * " << i << " = " << num*i << endl;
    }
}

int largestElement(const vector<int>& arr, int n){
    // //Find largest element in an array
    // int largest = arr[0];
    // for(int i = 1; i < n; i++){
    //     if(arr[i] > largest){
    //         largest = arr[i];
    //     }
    // }
    // return largest;
    return *max_element(arr.begin(), arr.end());
}


int main(){
    int a, b;
    cout << "Enter a number to reverse: ";
    cin >> a;
    cout << "Reversed Number =" << reverseNumber(a) << endl;

    cout << "Enter a number to check palindrome: ";
    cin >> a;
    if(isPalindrome(a))
        cout << a << " is a Palindrome Number" << endl;
    else
        cout << a << " is not a Palindrome Number" << endl;

    cout << "Enter two numbers to find GCD: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;

    int num2;
    cout << "Enter a number for multiplication table: ";
    cin >> a;
    multiplicationTable(a);
    
    cout << "Enter number of elements in array: ";  
    cin >> a;
    vector<int> arr(a);
    cout << "Enter " << a << " elements: ";
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    cout << "Largest element in the array is: " << largestElement(arr, a) << endl;

    return 0;
}