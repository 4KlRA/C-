#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    // Check strong number
    int num, sum = 0;
    cout << "Enter a number: ";
    cin >> num;
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += fact[digit];
        temp /= 10;
    }
    if (sum == num) {
        cout << num << " is a strong number." << endl;
    } else {
        cout << num << " is not a strong number." << endl;
    }
    //Find LCM of two numbers
    int a, b, lcm;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int gcd = 1;
    for(int i=1; i<=min(a,b); i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }  
    lcm = (a * b) / gcd;
    cout << "LCM of " << a << " and " << b << " = " << lcm << endl;
    //Reverse an array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Reversed array: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //Count frequency of elements in array
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }
    //Basic binary search
    int n1, key;
    cout << "Enter the size of the sorted array: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;
    int left = 0, right = n1 - 1;
    bool found = false;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr1[mid] == key) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        } else if (arr1[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "Element not found in the array." << endl;
    } 
    return 0;
}