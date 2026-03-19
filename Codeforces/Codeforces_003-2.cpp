#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n >0){
        for(int i = 5; i > 0; i--){
            while(n >= i){
                n -= i;
                count++;
            }
        }
    cout << count;
    return 0;
    }
}