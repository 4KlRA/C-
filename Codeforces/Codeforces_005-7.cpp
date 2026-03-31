#include <iostream>
using namespace std;

int main(){
    int n, m1;
    cin >> n >> m1;
    int count = 1;
    if (n == 1){
        cout << count << endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        int m2;
        cin >> m2;
        if(m1 == m2){
            continue;
        } else if (m1 != m2){
            m1 = m2;
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}