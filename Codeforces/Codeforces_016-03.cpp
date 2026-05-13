#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int price = 0;
    if(n % m == 0) price = (n * a > m * b) ? (n / m) * b : n * a;
    else price = ((n % m) * a > b) ? ((n / m) + 1) * b : (n % m) * a + (n / m) * b;
    cout << price << endl;
	return 0;
}