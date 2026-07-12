#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    int i = 0;
    if(n[0] == '9') {
            i++;
    }
    for(i; i < n.size(); i++) {
        if(n[i] - '0' > 4) {
            n[i] = '9' - (n[i] - '0');
        }
    }
    cout << n << endl;
    return 0;
}