#include <iostream>
using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;
    int total = k * (w * (w + 1) / 2);
    if(total > n){
        cout << total - n;
    }
    else{
        cout << 0;
    }
}