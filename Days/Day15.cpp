#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

set<int> intersection(const vector<int>& arr1, const vector<int>& arr2) {
    set<int> set1(arr1.begin(), arr1.end());
    set<int> result;
    for (int num : arr2) {
        if (set1.find(num) != set1.end()) {
            result.insert(num);
        }
    }
    return result;
}

string removeDuplicates(const string&str) {
    unordered_set<char> seen;
    string result;
    for (char c : str) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

int maxSubArraySum(const vector<int>&arr) {
    int current_sum = 0, maximum_sum = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        maximum_sum = max(maximum_sum, current_sum);
    }
    return maximum_sum;
}

int main() {
    // Find intersection of two sorted arrays
    cout << "Enter size of first array: ";
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) cin >> arr1[i];
    cout << "Enter size of second array: ";
    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) cin >> arr2[i];
    set<int> result = intersection(arr1, arr2);
    cout << "Intersection of the two arrays: ";
    for (int num : result) cout << num << " ";
    cout << endl;
    // Remove duplicate characters from string
    cout << "Enter a string: ";
    string str;
    cin >> str;
    str = removeDuplicates(str);
    cout << "String after removing duplicates: " << str << endl;
    // Find maximum subarray sum (basic Kadane approach)
    cout << "Enter size of array: ";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int max_sum = maxSubArraySum(arr);
    cout << "Maximum subarray sum: " << max_sum << endl;
    return 0;
}