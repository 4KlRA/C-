#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool easy = false;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1){
            easy = true;
            break;
        }
    }
    if (!easy) {
        cout << "EASY" << endl;
    } else {
        cout << "HARD" << endl;
    }
    return 0;
}