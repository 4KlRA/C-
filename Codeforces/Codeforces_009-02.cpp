#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drink_toasts = (k * l) / nl;
    int lime_toasts = c * d;
    int salt_toasts = p / np;

    int total_toasts = min({drink_toasts, lime_toasts, salt_toasts});

    cout << total_toasts / n << endl;

    return 0;
}