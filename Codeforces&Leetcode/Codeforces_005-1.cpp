#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long int n, m, a;
    cin >> n >> m >> a;
    long long int tiles = (ceil(double(n)/double(a))) * (ceil(double(m)/double(a)));
    cout << tiles << endl;
    return 0;
}