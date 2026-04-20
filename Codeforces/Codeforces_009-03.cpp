#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count = 0; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int mx = arr[0], mn = arr[0];
    for(int i = 1; i < n; i++){
        if(mx < arr[i]){
            mx = arr[i];
            count++;
        }
        if(mn > arr[i]){
            mn = arr[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}