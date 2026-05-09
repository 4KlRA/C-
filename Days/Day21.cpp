#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearchFirstOccurrence(const vector<int>& arr, int size, int target) {
    int left = 0, right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int binarySearchLastOccurrence(const vector<int>& arr, int size, int target) {
    int left = 0, right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

bool canBeSortedByOneSwap(vector<int> arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    vector<int> diff;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != sorted[i]) {
            diff.push_back(i);
        }
    }

    if (diff.empty()) {
        return true;
    }

    if (diff.size() != 2) {
        return false;
    }
}

int main() {
    // Find first occurrence using binary search
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter target element: ";
    cin >> target;
    int firstOccurrence = binarySearchFirstOccurrence(arr, n, target);
    if (firstOccurrence != -1) {
        cout << "First occurrence of " << target << " is at index: " << firstOccurrence << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    // Find last occurrence using binary search
    int lastOccurrence = binarySearchLastOccurrence(arr, n, target);
    if (lastOccurrence != -1) {
        cout << "Last occurrence of " << target << " is at index: " << lastOccurrence << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    // Check if array can become sorted after one swap
    if (canBeSortedByOneSwap(arr)) {
        cout << "The array can be sorted by at most one swap." << endl;
    } else {
        cout << "The array cannot be sorted by at most one swap." << endl;
    }
    return 0;
}