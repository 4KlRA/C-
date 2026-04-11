#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void primeNumbersInRange(int lower, int upper){
    // Check prime numbers in a range
    cout << "Prime numbers between " << lower << " and " << upper << " are: ";
    for (int num = lower; num <= upper; num++){
        bool isPrime = true;
        if (num <= 1) {
            isPrime = false;
        } else {
            for (int i = 2; i*i <= num; i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            cout << num << " ";
        }
    }
}

int sumOfArray(const vector<int>& arr, int n){
    // Find sum of array elements
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

vector<int> leftRotateArray(vector<int>& arr, int n, int d){
    // Left rotate an array
    vector<int> leftRotated(n);
    for(int i = d, j = 0; i > 0; i--, j++){
        leftRotated[n-i] = arr[j];
    }
    for(int i = 0; i < n-d; i++){
        leftRotated[i] = arr[i+d];
    }
    return leftRotated;
}

vector<int> rightRotateArray(vector<int>& arr, int n, int d){
    // Right rotate an array
    vector<int> rightRotated(n);
    for(int i = n-d, j = 0; i < n; i++, j++){
        rightRotated[j] = arr[i];
    }
    for(int i = 0; i < n-d; i++){
        rightRotated[i+d] = arr[i];
    }
    return rightRotated;
}

void duplicateElements(const vector<int>& arr, int n){
    // Find duplicate elements in an array
    cout << "\nDuplicate elements in array: ";
    int maxval = 0;
    for (int i = 0; i < n; i++) {
        maxval = max(maxval, arr[i]);
    }
    vector<int> freq(maxval + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    for (int i = 0; i <= maxval; i++) {
        if (freq[i] > 1) {
            cout << i << "-" << freq[i] << " times ";
        }
    }
}

int main(){
    int a, b;
    cout << "Enter lower and upper bounds: ";
    cin >> a >> b;
    primeNumbersInRange(a, b);

    cout <<"\nEnter number of elements in array: ";
    cin >> a;
    vector<int> arr(a);
    cout << "Enter elements of array: ";
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    cout << "\nSum of array elements: " << sumOfArray(arr, a) << endl;

    cout << "Enter the number of elements in array: ";
    cin >> a;
    cout << "Enter number of positions to left rotate: ";
    cin >> b;
    vector<int> arrL(a);
    cout << "Enter elements of array: ";
    for (int i = 0; i < a; i++) {
        cin >> arrL[i];
    }
    vector<int> leftRotated = leftRotateArray(arrL, a, b);
    cout << "Left rotated array: ";
    for(int i = 0; i < a; i++){
        cout << leftRotated[i] << " ";
    }

    cout << "\nEnter number of elements in array: ";
    cin >> a;
    vector<int> arrR(a);
    cout << "Enter number of positions to right rotate: ";
    cin >> b;
    cout << "Enter elements of array: ";
    for (int i = 0; i < a; i++) {
        cin >> arrR[i];
    }
    vector<int> rightRotated = rightRotateArray(arrR, a, b);
    cout << "Right rotated array: ";
    for(int i = 0; i < a; i++){
        cout << rightRotated[i] << " ";
    }

    cout << "\nEnter number of elements in array: ";
    cin >> a;
    vector<int> arrD(a);
    cout << "Enter elements of array: ";
    for (int i = 0; i < a; i++) {
        cin >> arrD[i];
    }
    duplicateElements(arrD, a);

    return 0;
}