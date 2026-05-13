#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

vector<pair<int, int>> findPairsWithTargetSum(const vector<int>& arr, int target) {
    vector<pair<int, int>> pairs;
    unordered_set<int> seen;

    for (int num : arr) {
        int complement = target - num;
        if (seen.count(complement)) {
            pairs.emplace_back(num, complement);
        }
        seen.insert(num);
    }

    return pairs;
}

bool hasAllUniqueCharacters(const string& str) {
    set<char> charSet(str.begin(), str.end());
    if(charSet.size() != str.size()) {
        return false; 
    }
    return true;
}

vector<int> prefixSumArray(const vector<int>& arr) {
    vector<int> prefixSum(arr.size());
    prefixSum[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    return prefixSum;
}

int main() {
    // Find pair with target sum in array
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << "Enter the target sum: ";
    cin >> target;
    vector<pair<int, int>> pairs = findPairsWithTargetSum(arr, target);
    cout << "Pairs with target sum " << target << ":\n";
    for (const auto& p : pairs) cout << "(" << p.first << ", " << p.second << ")\n";

    // Check if string contains only unique characters
    string str;
    cout << "Enter a string: ";
    cin >> str;
    if (hasAllUniqueCharacters(str)) cout << "The string contains all unique characters.\n";
    else cout << "The string does not contain all unique characters.\n";

    // Implement prefix sum array
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> prefixSum = prefixSumArray(arr);
    cout << "Prefix sum array: ";
    for (int sum : prefixSum) cout << sum << " ";
    cout << "\n";

    return 0;
}