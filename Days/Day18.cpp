#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <climits>
#include <limits>
#include <unordered_map>
using namespace std;

bool areAnagrams(string s1, string s2) {
    vector<int> freq(26, 0);

    for(char ch : s1) {
        if (isalpha(ch)) freq[tolower(ch) - 'a']++;
    }
    for(char ch : s2) {
        if (isalpha(ch)) freq[tolower(ch) - 'a']--;
    }
    for(int count : freq) {
        if(count != 0) return false;
    }
    return true;
}

int findMaxOccurringElement(vector<int>& arr) {
    if (arr.empty()) return -1;

    unordered_map<int, int> freq;

    for(int num : arr) {
        freq[num]++;
    }

    int max_count = INT_MIN;
    int max_element = -1;
    for(auto& pair : freq) {
        if(pair.second > max_count) {
            max_count = pair.second;
            max_element = pair.first;
        }
    }
    return max_element;
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int min_index = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min_index]) min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    // Check anagram using frequency array
    string s1, s2;
    cout << "Enter two strings to check for anagram: ";
    getline(cin, s1);
    getline(cin, s2);

    if(areAnagrams(s1, s2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
    
    // Find maximum occurring element in array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) cin >> arr1[i];
    int maxElement = findMaxOccurringElement(arr1);
    cout << "The maximum occurring element is: " << maxElement << endl;

    // Implement selection sort
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) cin >> arr2[i];
    selectionSort(arr2);
    cout << "The array after selection sort is: ";
    for(int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}