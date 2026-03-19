#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    string s;
    cin >> s;
    unordered_set<char> distinct_chars(s.begin(), s.end());
    if (distinct_chars.size() % 2 == 0){
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }
    return 0;
}