#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, x, m = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cin >> b[i];
    }
    x = b[0];
    for (int i = 1; i < n - 1; i++){
        m = max(m, (x + (b[i] - a[i])));
        x = (x + (b[i] - a[i]));
    }
    cout << m << endl;
    return 0;
}