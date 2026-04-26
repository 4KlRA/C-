#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int diagonal = min(n, m);
    if (diagonal % 2 == 0) cout << "Malvika\n";
    else cout << "Akshat\n";
    return 0;
}