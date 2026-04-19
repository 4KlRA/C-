#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int x = a * b * c;
    int y = a + b + c;
    int z = a * (b +c);
    int w = (a + b) * c;
    cout << max({x, y, z, w});
    return 0;
}