#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int p[101], res[101];
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    for (int i = 1; i <= n; i++) {
        res[p[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}