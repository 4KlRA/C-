#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool isPalindrome(int num) {
    if (num < 0) return false;
    int originalNum = num;
    int reverseNum = 0;
    while(num > 0) {
        int digit = num % 10;
        reverseNum = reverseNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reverseNum;
}

int equilibriumIndex(vector<int>& arr, int n) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int leftSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum -= arr[i];
        if(leftSum == totalSum) {
            return i;
        }
        leftSum += arr[i];
    }

    return -1;
}

int countOccurrences(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            int count = 1;
            int leftIndex = mid - 1;
            while(leftIndex >= 0 && arr[leftIndex] == target) {
                count++;
                leftIndex--;
            }
            int rightIndex = mid + 1;
            while(rightIndex < arr.size() && arr[rightIndex] == target) {
                count++;
                rightIndex++;
            }
            return count;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main () {
    // Check if number is palindrome without string conversion
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPalindrome(n)) {
        cout << n << " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }

    // Find equilibrium index in array
    cout << "Enter size of array: ";
    int size;   
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements of array: ";
    for(int i = 0; i < size; i++) cin >> arr[i];
    int eqIndex = equilibriumIndex(arr, size);
    if (eqIndex != -1) {
        cout << "Equilibrium index is: " << eqIndex << endl;
    } else {
        cout << "No equilibrium index found." << endl;
    }

    // Count occurrences using binary search
    cout << "Enter size of sorted array: ";
    int sortedSize;
    cin >> sortedSize;
    vector<int> sortedArr(sortedSize);
    cout << "Enter elements of sorted array: ";
    for(int i = 0; i < sortedSize; i++) cin >> sortedArr[i];
    cout << "Enter target number to count occurrences: ";
    int target;
    cin >> target;
    int count = countOccurrences(sortedArr, target);
    cout << "Number of occurrences of " << target << ": " << count << endl;
    return 0;           
}