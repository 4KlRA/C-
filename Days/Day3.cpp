#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int sumOfDigits(int n){
     //Sum of digits of a number
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int numberOfDigits(int n){
    //Count digits in a number
    int digits = 0;
    while (n > 0) {
        n /= 10;
        digits++;
    }
    return digits;
}

bool isArmstrong(int n){
    //Check Armstrong number
    int  order;
    order = to_string(n).length();
    int originalNum = n;
    int armstrongSum = 0;
    while (n > 0){
        int digit = n % 10;
        armstrongSum += pow(digit, order);
        n /= 10;
    }
    return originalNum == armstrongSum;
}

int linearSearch(const vector<int>& arr, int n, int key){
    //Linear search in an array
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int secondLargestElement(const vector<int>& arr, int n){
    //Find second largest element in an array
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){
    int a;
    cout<<"Enter a number for sum of digits: ";
    cin>>a;
    cout << "Sum of digits: " << sumOfDigits(a) << endl;

    cout << "Enter a number for counting digits: ";
    cin >> a;
    cout << "Number of digits: " << numberOfDigits(a) << endl;
    
    cout << "Enter a number for checking Armstrong: ";
    cin >> a;
    if (isArmstrong(a)) {
        cout << a << " is an Armstrong number." << endl;
    } else {
        cout << a << " is not an Armstrong number." << endl;
    }
    
    int key;
    cout << "Enter number of elements in array: ";
    cin >> a;
    vector<int> arr(a);
    cout << "Enter elements of array: ";
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    cout << "Enter a number to search in array: ";
    cin >> key;
    int index = linearSearch(arr, a, key);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in array." << endl;
    }

    cout << "Second largest element in array: " << secondLargestElement(arr, a) << endl;

    return 0;
}