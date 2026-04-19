#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s;
        for (char &c : s) {
            c = std::toupper((unsigned char)c);
        }
        if(s == "YES") cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}