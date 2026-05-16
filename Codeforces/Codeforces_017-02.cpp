#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        int len = 0;
        cin >> n;
        cin >> s;
        for(int i = 0; 2 * i < n; i++) {
            if((s[i] == '1' && s[n-i-1] == '0') || (s[i] == '0' && s[n-i-1] == '1')) len +=  2;
            else {
                break;
            }
        }
        cout << n - len << endl;
    }
    return 0;
}