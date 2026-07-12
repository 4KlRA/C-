#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    for (int i = 0; i + 2 < s.length(); ) {
        if (s.substr(i, 3) == "WUB") {
            s.replace(i, 3, " ");
        } else {
            i++;
        }
    }

    string word;
    for (char c : s) {
        if (c == ' ') {
            if (!word.empty()) {
                cout << word << " ";
                word.clear();
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) cout << word;
    
    return 0;
}