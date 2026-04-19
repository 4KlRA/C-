#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int max_idx = max_element(a.begin(), a.end()) - a.begin();
    int min_idx = min_element(a.begin(), a.end()) - a.begin();

    int count = 0;

    // Move max to front
    count += max_idx;

    // If min is before max, its index increases after max moves
    if(min_idx < max_idx){
        min_idx++;
    }

    // Move min to end
    count += (n - 1 - min_idx);

    cout << count << endl;

    return 0;
}