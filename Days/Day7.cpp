#include <bits/stdc++.h>
using namespace std;

vector<int> mergeArrays(const vector<int>& a, const vector<int>& b){
    vector<int> merged;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            merged.push_back(a[i++]);
        } else {
            merged.push_back(b[j++]);
        }
    }
    while(i < a.size()) merged.push_back(a[i++]);
    while(j < b.size()) merged.push_back(b[j++]);
    return merged;
}

vector<int> intersection(const vector<int>& a, const vector<int>& b){
    set<int> intersection;
    set<int> s(a.begin(), a.end());
    for(int x : b){
        if(s.count(x)){
            intersection.insert(x);
        }
    }
    return vector<int>(intersection.begin(), intersection.end());
}

int vowelCount(const string& s){
    int count = 0;
    for(char c : s){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            count++;
        }
    }
    return count;
}

string reverseString(const string& s){
    string reversed(s.rbegin(), s.rend());
    // string reversed;
    // for(int i = s.length() - 1; i >= 0; i--){
    //     reversed += s[i];
    // }
    return reversed;
}
bool areAnagrams(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main(){
    // Merge two arrays
    vector<int> a, b;
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter elements of first array: ";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << "Enter size of second array: ";
    cin >> m;
    cout << "Enter elements of second array: ";
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    vector<int> merged = mergeArrays(a, b);
    cout << "Merged array: ";
    for(int x : merged){
        cout << x << " ";
    }
    cout << endl;


    // Find intersection of arrays
    vector<int> intersect = intersection(a, b);
    cout << "Intersection: ";
    for(int x : intersect){
        cout << x << " ";
    }
    cout << endl;

    // Count vowels in string
    string s;
    cout << "Enter a string: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    cout << "Number of vowels: " << vowelCount(s) << endl;

    // Reverse a string
    cout << "Reversed string: " << reverseString(s) << endl;

    // Check anagram
    string s1, s2;
    cout << "Enter first string for anagram check: ";
    getline(cin, s1);
    cout << "Enter second string for anagram check: ";  
    getline(cin, s2);
    if(areAnagrams(s1, s2)){
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}