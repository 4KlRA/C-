#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <limits>
#include <set>
using namespace std;

vector<int> unionOfArrays(vector<int>& arr1, vector<int>& arr2) {
    // vector<int> result;
    // for (int num : arr1) {
    //     if (find(result.begin(), result.end(), num) == result.end()) {
    //         result.push_back(num);
    //     }
    // }
    // for (int num : arr2) {
    //     if (find(result.begin(), result.end(), num) == result.end()) {
    //         result.push_back(num);
    //     }
    // }
    unordered_set<int> resultSet;
    for (int num : arr1) {
        resultSet.insert(num);
    }
    for (int num : arr2) {
        resultSet.insert(num);
    }
    return vector<int>(resultSet.begin(), resultSet.end());
}

void removeDuplicates(vector<int>& arr) {
    set<int> result;
    for (int num : arr) {
        result.insert(num);
    }
    arr = vector<int>(result.begin(), result.end());
}

int countFrequency(const string& str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

vector<int> findMissingNumbers(vector<int>& arr) {
    unordered_set<int> arrSet(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());
    vector<int> missingNumbers;
    for (int i = 1; i <= mx; i++) {
        if (arrSet.find(i) == arrSet.end()) {
            missingNumbers.push_back(i);
        }
    }
    return missingNumbers;
}

int main(){
    //Find union of arrays
    vector<int> arr1;
    vector<int> arr2;
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) {
        int num;
        cin >> num;
        arr1.push_back(num);
    }
    cout << "Enter size of second array: ";
    cin >> n2;
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) {
        int num;
        cin >> num;
        arr2.push_back(num);
    }
    vector<int> unionArr = unionOfArrays(arr1, arr2);
    cout << "Union of the two arrays: ";
    for (int num : unionArr) {
        cout << num << " ";
    }
    cout << endl;
    //Remove duplicates from array
    removeDuplicates(arr1);
    cout << "First Array after removing duplicates: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;
    //Count frequency of characters in string
    string str;
    char ch;
    cout << "Enter a string: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);
    cout << "Enter a character to count: ";
    cin >> ch;
    int frequency = countFrequency(str, ch);
    cout << "Frequency of '" << ch << "' in the string: " << frequency << endl;
    //Check palindrome string
    cout << "Is the string a palindrome? " << (isPalindrome(str) ? "Yes" : "No") << endl;
    //Find missing number in array (1 to n)
    int n;
    cout << "Enter size of array): ";
    cin >> n;
    vector<int> arr;
    cout << "Enter elements of array (1 to max exist): ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    vector<int> missingNumbers = findMissingNumbers(arr);
    cout << "Missing numbers in the array: ";
    for (int num : missingNumbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}