#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1;

    s2.resize(s1.length());

    if (isupper(s1[0])) 
        s2[0] = tolower(s1[0]);
    else 
        s2[0] = toupper(s1[0]);

    for (int i = 1; i < s1.length(); i++) {
        if (!isupper(s1[i])) {
            cout << s1;
            return 0;
        }
        s2[i] = tolower(s1[i]);
    }

    cout << s2;
    return 0;
}