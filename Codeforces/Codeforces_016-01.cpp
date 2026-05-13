#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        unordered_set<int> a(arr.begin(), arr.end());
        if(a.find(k) != a.end()) cout << "YES\n";
        else cout << "NO\n";
    }
	return 0;
}