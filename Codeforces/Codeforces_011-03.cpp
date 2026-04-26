#include <bits/stdc++.h>
#include <bit>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (has_single_bit(x)) {
        cout << 1 << endl;
    } else {
        int bits = log2(x) + 1;
        int result = x - (1 << (bits - 1));
        cout << result << endl;
    }

    return 0;
}