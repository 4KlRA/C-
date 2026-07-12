#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, num, place = 0, count = 0;
	cin >> t;
	vector<int> arr;
	for(int i = 0; i < t; i++){
	    cin >> num;
	    while(num > 0){
	        if(num % 10 == 0){
	            num /= 10;
	            place ++;
	        } else{
	            arr.push_back((num % 10)*pow(10, place));
	            num /= 10;
	            place++;
	            count++;
	        }
	    }
	    cout << count << endl;
	    for(int i = 0; i < arr.size(); i++){
	        cout << arr[i] << " ";
	    }
	    count = 0;
	    place = 0;
	    arr.clear();
	    cout << endl;
	}
	
    return 0;
}