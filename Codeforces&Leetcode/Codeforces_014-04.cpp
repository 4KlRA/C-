#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, diff;
    cin >> t;
    while(t--) {
        bool yes = true;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(n != 1) {
            sort(a.begin(), a.end());
            for (int i = 0; i < n-1; i++) {
                diff = a[i+1] - a[i];
                if(diff > 1) {
                yes = false;
                break;
                }
        }
        if(yes) cout << "YES\n";
        else cout << "NO\n";
        } else cout << "YES\n";
    }
    return 0;
}