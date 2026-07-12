#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        cout << (s[0] - '0') + (s[1] - '0') << endl;
    }
	return 0;
}