#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isSubstring(string str, string sub){
    return str.find(sub) != string::npos;
}

int wordCount(string sentence){
    int wordCount(string s){
    int count = 0;
    bool inWord = false;

    for(char c : s){
        if(c != ' ' && !inWord){
            count++;
            inWord = true;
        } else if(c == ' '){
            inWord = false;
        }
    }
    return count;
    }
}

vector<int> minMax(vector<int> arr, int n){
    int mn = arr[0], mx = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return {min, max};
}

void moveZerosToEnd(vector<int>& arr){
    int j = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

bool isSorted(vector<int> arr, int n){
    bool isSorted(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;
    }
}

int main(){
    // Check substring in string
    string s, sub;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Enter a substring to search in " << s << ": ";
    cin >> sub;
    if(isSubstring(s, sub)){
        cout << "Substring found in the string." << endl;
    } else{
        cout << "Substring not found in the string." << endl;
    }
    // Count words in a sentence
    string sentence;
    cout << "Enter a sentence: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, sentence);
    cout << "Number of words in the sentence: " << wordCount(sentence) << endl;
    // Find largest & smallest in array (single pass)
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> result = minMax(arr, n);
    cout << "Minimum element: " << result[0] << endl;
    cout << "Maximum element: " << result[1] << endl;
    // Move zeros to end of array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    moveZerosToEnd(arr, n);
    cout << "Array after moving zeros to the end: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    // Check sorted array or not
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(isSorted(arr, n)){
        cout << "The array is sorted." << endl;
    } else{
        cout << "The array is not sorted." << endl;
    }
    return 0;
}