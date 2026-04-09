#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(c.rbegin(), c.rend());
    for(int i = 0; i < n; i++){
        int sum1 = 0;
        for(int j = 0; j <= i; j++){
            sum1 += c[j];
        }
        int sum2 = 0;
        for(int j = i+1; j < n; j++){
            sum2 += c[j];
        }
        if(sum1 > sum2){
            cout << i+1;
            break;
        }
    }
    return 0;
}