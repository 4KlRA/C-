#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum1 = 0, sum2 = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
	    cin >> arr[i];  
    }
    int* lptr = &arr[0];
    int* rptr = &arr[n-1];
    while(lptr <= rptr) {
        if(*lptr > *rptr) {
            sum1 += *lptr;
            lptr++;
        } else {
            sum1 += *rptr;
            rptr--;
        }

        if(lptr > rptr) break;

        if(*lptr > *rptr) {
            sum2 += *lptr;
            lptr++;
        } else {
            sum2 += *rptr;
            rptr--;
        }
    }
    cout << sum1 << " " << sum2 << "\n";
    return 0;
}