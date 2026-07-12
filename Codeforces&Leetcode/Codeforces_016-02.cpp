#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a;
    cin >> t;
    while(t--) {
        int max = 0, cur = 0;
        cin >> n;
        while(n--) {
            cin >> a;
            if(a == 0) cur++;
            else cur = 0;
            if(cur > max) max = cur;
        }
        cout << max << endl;
    }
	return 0;
}