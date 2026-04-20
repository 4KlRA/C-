#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        int sum1 = 0, sum2 = 0;

        sum1 += (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
        sum2 += (s[3] - '0') + (s[4] - '0') + (s[5] - '0');

        if (sum1 == sum2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}