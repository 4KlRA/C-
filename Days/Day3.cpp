#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    //Sum of digits of a number
    int n;
    cout<<"Enter a number for sum of digits: ";
    cin>>n;
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    cout<<"Sum of digits: "<<sum<<endl;
    //Count digits in a number
    int n2, digits = 0;
    cout << "Enter a number for counting digits: ";
    cin >> n2;
    while (n2 > 0) {
        n2 /= 10;
        digits++;
    }
    cout << "Number of digits: " << digits << endl;
    //Check Armstrong number
    int n3, order;
    cout << "Enter a number for checking Armstrong: ";
    cin >> n3;
    order = to_string(n3).length();
    int originalNum = n3;
    int armstrongSum = 0;
    while (n3 > 0){
        int digit = n3 % 10;
        armstrongSum += pow(digit, order);
        n3 /= 10;
    }
    if (originalNum == armstrongSum) {
        cout << originalNum << " is an Armstrong number." << endl;
    } else {
        cout << originalNum << " is not an Armstrong number." << endl;
    }
    //Linear search in an array
    int n4, key;
    cout << "Enter the size of the array: ";
    cin >> n4;
    int arr[n4];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n4; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;
    // Perform linear search
    bool found = false;
    for (int i = 0; i < n4; i++) {
        if (arr[i] == key) {
            cout << "Key found at index " << i << endl;
            found = true;
            break;
        }
    }
    if(!found){
    cout << "Key not found\n";
    }
    //Second largest element in an array
    int largest, secondLargest;
    largest = arr[0];
    secondLargest = INT_MIN;
    if(n4 < 2){
    cout << "Second largest not possible\n";
    return 0;
    } else{
    for (int i = 1; i < n4; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    cout << "Second largest element: " << secondLargest << endl;
    }
    return 0;
}