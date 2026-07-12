#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, num, count = 0;
	cin >> t;
	int one = 0, two = 0, three = 0;
	for(int i = 0; i < t; i++){
	    cin >> num;
	    if (num == 1) one++;
	    else if (num == 2) two++;
	    else if (num == 3) three++;
	    else count++;
	}
	while(one != 0 && three != 0){
	    count++;
	    one--;
	    three--;
	}
	while(one > 0 && two != 0){
	    count++;
	    one -= 2;
	    two--;
	}
	(one != 0) ? count += (one + 3)/4 : count += three;
	count += (two + 1)/2;
	cout << count;
	return 0;
}