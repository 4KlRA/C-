#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool isPalindrome(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int countDistinct(const vector<int>& arr) {
    unordered_map<int, int> countMap;
    for (int num : arr) {
        countMap[num]++;
    }
    return countMap.size();
}

int main(){
    // Find GCD using Euclidean algorithm
    int a, b;
    cout << "Enter two numbers to find their GCD: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    // Check if array is palindrome
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (isPalindrome(arr)) {
        cout << "The array is a palindrome." << endl;
    } else {
        cout << "The array is not a palindrome." << endl;
    }
    // Count distinct elements in array
    cout << "Number of distinct elements: " << countDistinct(arr) << endl;
}