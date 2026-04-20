#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
	    cin >> n;
	    if((n + 1) % 3 == 0 || (n - 1) % 3 == 0){
	        cout << "First" << endl;
	    } else {
	        cout << "Second" << endl;
	    }
	}
    return 0;
}