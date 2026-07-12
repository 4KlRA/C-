#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    if(n % 2 == 0) {
        m = n / 2;
        if(n % 4 == 0) cout << m << " " << m;
        else cout << m - 1 << " " << m + 1;
    } else cout << 9 << " " << n - 9;
    return 0;
}