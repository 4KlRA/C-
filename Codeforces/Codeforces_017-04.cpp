#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int count = 0;
        int i = 0;
        while(count != n) {
            i++;
            if(i % 3 != 0 && i % 10 != 3) count++;
        }
        cout << i << endl;
    }
    return 0;
}