#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool perfectNumber(int n){
    //Check if a number is perfect number
    int sum = 0;
    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

void divisors(int n){
    //Print all divisors of a number
    cout << "Divisors of " << n << " are: ";
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void evenOddCount(const vector<int>& arr, int n){
    //Count even and odd elements in an array
    int evenCount = 0, oddCount = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    cout << "Even elements: " << evenCount << endl;
    cout << "Odd elements: " << oddCount << endl;
}

int smallestElement(const vector<int>& arr, int n){
    //Find smallest element in an array
    int smallest = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

void swapWithoutThirdVariable(int &a, int &b){
    //Swap two numbers without using a third variable
    a = a + b;
    b = a - b;
    a = a - b;
}

int main(){
    int a, b;
    cout << "Enter a number to check perfect number: ";
    cin >> a;
    if(perfectNumber(a))
        cout << "Perfect number" << endl;
    else
        cout << "Not a perfect number" << endl;

    cout << "Enter a number to find its divisors: ";
    cin >> a;
    divisors(a);

    cout << "Enter number of elements in array: ";  
    cin >> a;
    vector<int> arr(a);
    for(int i = 0; i < a; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    evenOddCount(arr, a);

    cout << "Smallest element: " << smallestElement(arr, a) << endl;

    cout << "Enter two numbers to swap: ";
    cin >> a >> b;
    swapWithoutThirdVariable(a, b);
    cout << "After swapping: " << a << " " << b << endl;


    return 0;
}