#include  <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int total = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        total = total + x;
    }
    cout << double(total) / n << endl;
    return 0;
}