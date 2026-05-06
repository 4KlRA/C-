#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        double diff = abs(a-b);
        int steps = ceil(diff/10);
        cout << steps << endl;
    }
    return 0;
}