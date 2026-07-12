#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string target = "codeforces";
    cin >> t;
    char s;
    while(t--) {
        cin >> s;
        bool targetFound = false;
        for(char ch : target) {
            if (ch == s) targetFound = true;
        }
        if (targetFound) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}