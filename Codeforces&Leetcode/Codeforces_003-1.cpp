#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = 1; a <= b; i++){
        a *= 3;
        b *= 2;
        if(a > b){
            cout << i;
            break;
        }
    }
    return 0;
}