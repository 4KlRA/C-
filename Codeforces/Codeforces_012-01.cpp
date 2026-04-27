#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> score;
    string s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        score[s]++;
    }

    string max_key;
    int max_val = 0;

    for (const auto& pair : score) {
        if (pair.second > max_val) {
            max_val = pair.second;
            max_key = pair.first;
        }
    }

    cout << max_key;
    return 0;
}