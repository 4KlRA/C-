#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, m;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    cin >> q;
    while (q--) {
        cin >> m;

        int count = upper_bound(x.begin(), x.end(), m) - x.begin();

        cout << count << endl;
    }

    return 0;
}