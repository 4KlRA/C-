#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    vector<int> a(n);
	    for(int i = 0; i < n; i++) cin >> a[i];
	    if(a[0] == a[1]) {
	        if(a[1] == a[2]) {
	            for(int i = 2; i < n; i++) {
	                if(a[i] != a[0]) {
	                    cout << i + 1 << endl;
	                    break;
	                }
	            }
	        } else cout << 3 << endl;
	    } else (a[1] == a[2]) ? cout << 1 << endl : cout << 2 << endl;
	}
	return 0;
}