#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, max = 0, count = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	for(int i = 0; i < n - 1; i++){
	    if(arr[i] > arr[i+1]){
	    	if(count > max) max = count;
	        count = 0;
	    } else {
	        count++;
	    }
	}
	cout << (max > count ? ++max : ++count) << endl;
    return 0;
}