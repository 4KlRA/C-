#include <iostream>
#include <vector>
using namespace std;

//Memory Limit Exceeded
// int main(){
//     int n, k;
//     cin >> n >> k;
//     vector <int> res;
//     for(int i = 1; i <= n; i++){
//         if(i%2 == 1){
//             res.push_back(i);
//         }
//     }
//     for(int i = 1; i <= n; i++){
//         if(i%2 == 0){
//             res.push_back(i);
//         }
//     }
//     cout << res[k-1];
//     return 0;
// }

int main(){
    long long n,k;
    cin >> n >> k;
    if(k <= (n+1)/2){
        cout << 2*k-1;
    }
    else{
        cout << 2*(k-(n+1)/2);
    }
    return 0;
}