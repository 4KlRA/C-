#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    string s;
    cin >> s;
    unordered_set<char> charSet; 
    for(char c: s){
        if(isalpha(c)){
            charSet.insert(tolower(c));
        }
    }
    if(charSet.size() == 26){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}