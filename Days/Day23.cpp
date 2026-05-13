#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
using namespace std;

vector<int> prefixSumArray(const vector<int>& arr) {
    vector<int> prefixSum(arr.size());
    prefixSum[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    return prefixSum;
}

int rangeSum(const vector<int>& prefixSum, int left, int right) {
    if(left == 0) return prefixSum[right];
    return prefixSum[right] - prefixSum[left - 1];
}

bool arePermutations(const string& str1, const string& str2) {
    if(str1.length() != str2.length()) return false;
    map<char, int> charCount;
    for(char c : str1) charCount[tolower(c)]++;
    for(char c : str2) {
        if(charCount[tolower(c)] == 0) return false;
        charCount[tolower(c)]--;
    }
    return true;
}

int main() {
    // Range sum query using prefix sums
    int n, left, right;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> prefixSum = prefixSumArray(arr);
    cout << "Enter the left and right indices for the range sum query: ";
    cin >> left >> right;
    cout << "Range sum from index " << left << " to " << right << ": " << rangeSum(prefixSum, left, right) << endl;

    // Check if two strings are permutations of each other
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    if(arePermutations(str1, str2)) {
        cout << "The strings are permutations of each other." << endl;
    } else {
        cout << "The strings are not permutations of each other." << endl;
    }
    return 0;
}