#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    auto x = max_element(a.begin(), a.end());
    int y = distance(a.begin(), x);
    while(*x != a[0]){
        for(int i = y; i > 0; i--){
            swap(a[i], a[i - 1]);
        }
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}