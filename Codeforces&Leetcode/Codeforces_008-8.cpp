#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int r1 = abs(a-b);
    int r2 = abs(b-c);
    int r3 = abs(a-c);

    cout << r1 + r2 + r3 - max({r1, r2, r3});
    return 0;
}