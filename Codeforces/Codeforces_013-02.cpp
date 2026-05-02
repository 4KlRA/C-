#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    unordered_map<string, int> database;
    for (int i = 0; i < n; i++) {
        cin >> s;
        database[s]++;
        if(database[s] == 1) cout << "OK" << "\n";
        else cout << s + to_string(database[s]) << "\n";
    }
    return 0;
}