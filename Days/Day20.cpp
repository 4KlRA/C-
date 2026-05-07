#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Target not found
}

vector<int> mergeSortedArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] <= b[j]) {
            result.push_back(a[i++]);
        } else {
            result.push_back(b[j++]);
        }
    }
    while(i < a.size()) result.push_back(a[i++]);
    while(j < b.size()) result.push_back(b[j++]);
    return result;
}

bool isSubsequence(const string& s1, const string& s2) {
    int i = 0, j = 0;
    while(i < s1.size() && j < s2.size()) {
        if(s1[i] == s2[j]) {
            j++;
        }
        i++;
    }
    return j == s2.size();
}

int main() {
    // Binary search in sorted array
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements (sorted): ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the target element: ";
    cin >> target;
    int index = binarySearch(arr, target);
    if(index != -1) cout << "Element found at index: " << index << endl;
    else cout << "Element not found in the array." << endl;

    // Merge two sorted arrays
    cout << "Arrays for merging: " << endl;
    cout << "Enter the number of elements in the 1st array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter the elements of the 1st array (sorted): ";
    for(int i = 0; i < n; i++) cin >> arr1[i];
    cout << "Enter the number of elements in the 2nd array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter the elements of the 2nd array (sorted): ";
    for(int i = 0; i < n; i++) cin >> arr2[i];

    vector<int> merged = mergeSortedArrays(arr1, arr2);
    cout << "Merged sorted array: ";
    for(auto elem : merged) {
        cout << elem << " ";
    }
    cout << endl;

    // Check if string is subsequence of another
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    if(isSubsequence(s1, s2)) {
        cout << "The second string is a subsequence of the first string." << endl;
    } else {
        cout << "The second string is not a subsequence of the first string." << endl;
    }

    return 0;
}