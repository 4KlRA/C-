#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

int secondLargest(const vector<int>& arr) {
    int largest = arr[0];
    int secondLargest = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

bool areArraysEqual(vector<int> arr1, vector<int> arr2) {
    if(arr1.size() != arr2.size()) return false;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for(int i = 0; i < arr1.size(); i++) {
        if(arr1[i] != arr2[i]) return false;
    }
    return true;
}

int main() {
    // Implement insertion sort
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    insertionSort(arr);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // Find second largest element without sorting
    cout << "Enter the number of elements: ";
    cin >> n;
    arr.resize(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    int secondLargestElement = secondLargest(arr);
    cout << "Second largest element: " << secondLargestElement << endl;
    // Check if two arrays are equal
    cout << "Enter the number of elements for first array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter the elements for first array: ";
    for(int i = 0; i < n; i++) cin >> arr1[i];
    cout << "Enter the number of elements for second array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter the elements for second array: ";
    for(int i = 0; i < n; i++) cin >> arr2[i];
    if(areArraysEqual(arr1, arr2)) {
        cout << "The arrays are equal." << endl;
    } else {
        cout << "The arrays are not equal." << endl;
    }
    return 0;
}