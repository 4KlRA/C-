#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, untreated = 0, count = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if (x == -1){
            (count + x < 0) ? untreated++ : count +=x;
        }
        else {
            count += x;
        }
    }
    cout << untreated;
    return 0;
}