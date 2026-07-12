#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, x;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int gap = a[0];
        for(int i = 0; i < n - 1; i++) {
            if(a[i + 1] - a[i] > gap)
                gap = a[i + 1] - a[i];
        }
        if(2 * (x - a[n - 1]) > gap)
            gap = 2 * (x - a[n - 1]);
        cout << gap << endl;
    }
    return 0;
}