#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    double ans = max(a[0], l - a[n - 1]);

    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, (a[i + 1] - a[i]) / 2.0);
    }

    cout << fixed << setprecision(10) << ans;
}