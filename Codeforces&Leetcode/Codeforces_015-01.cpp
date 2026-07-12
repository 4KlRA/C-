#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, sum;
    cin >> t;
    vector<int> num(3);
    while(t--) {
        cin >> num[0] >> num[1] >> num[2];
        sum = accumulate(num.begin(), num.end(), 0);
        sort(num.begin(), num.end());
        cout << sum - num[0] - num[2] << endl;
    }
    return 0;
}