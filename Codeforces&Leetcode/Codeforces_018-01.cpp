#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if(a[i] != mx) sum += mx - a[i];
    }
    cout  << sum;
    return 0;
}