#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isStrongNumber(int n){
    //Check strong number
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += fact[digit];
        temp /= 10;
    }
    return sum == n;
}

int lcm(int a, int b){
    //Find LCM of two numbers
    int gcd = 1;
    for(int i=1; i<=min(a,b); i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }  
    return (a * b) / gcd;
}

void reverseArray(vector<int>& arr, int n){
    //Reverse an array
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
}

void countFrequency(const vector<int>& arr, int n){
    //Count frequency of elements in an array
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }
}

int binarySearch(const vector<int>& arr, int n, int key){
    //Binary search in a sorted array
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Return index if found
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main(){
    int a, b;
    cout << "Enter a number to check strong number: ";
    cin >> a;
    if(isStrongNumber(a))
        cout << "Strong number" << endl;
    else
        cout << "Not a strong number" << endl;

    cout << "Enter two numbers to find LCM: ";
    cin >> a >> b;
    cout << "LCM of " << a << " and " << b << " = " << lcm(a, b) << endl;

    cout << "Enter size of array to reverse: ";
    cin >> a;
    vector<int> arr(a);
    cout << "Enter elements of array: ";
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    reverseArray(arr, a);
    cout << "Reversed array: ";
    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter size of array to count frequency: ";
    cin >> a;
    vector<int> arrF(a);
    cout << "Enter elements of array: ";
    for (int i = 0; i < a; i++) {
        cin >> arrF[i];
    }
    countFrequency(arrF, a);

    cout << "Enter size of sorted array for binary search: ";
    cin >> a;
    vector<int> sortedArr(a);
    cout << "Enter elements of sorted array: ";
    for (int i = 0; i < a; i++) {
        cin >> sortedArr[i];
    }
    cout << "Enter the key to search: ";
    cin >> b;
    int result = binarySearch(sortedArr, a, b);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
