#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd = 0;
        for (int f : freq) {
            if (f % 2) odd++;
        }

        if (odd <= k + 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}