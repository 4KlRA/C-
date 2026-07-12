#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n, x, y;
    cin >> s >> n;
    vector<pair<int, int>> dragons;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        dragons.push_back({x, y});
    }
    sort(dragons.begin(), dragons.end());
    for (const auto [x, y] : dragons) {
        if(s > x) s +=y;
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}