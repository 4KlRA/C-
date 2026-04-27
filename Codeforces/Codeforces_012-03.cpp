#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 0) {
        int unit = n % 10;
        n /= 10;
        int tens = n % 10;
        n /= 10;
        if (unit < tens) n = n * 10 + tens;
        else n = n * 10 + unit;
    }
    cout << n;
    return 0;
}