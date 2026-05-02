#include <bits/stdc++.h>
using namespace std;

int main() {
    int red, blue, count1, count2;
    cin >> red >> blue;
    count1 = min(red, blue);
    red -= count1;
    blue -= count1;
    count2 = (red > blue) ? ((red >= 2) ? red/2 : 0) : ((blue >= 2) ? blue/2 : 0);
    cout << count1 << " " << count2;
    return 0;
}