#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> Borze;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') Borze.push_back(0);
        else {
            if(s[i+1] == '.') {
                Borze.push_back(1);
                i++;
            } else {
                Borze.push_back(2);
                i++;
            }
        }
    }
    for(int i : Borze) cout << i;
    return 0;
}