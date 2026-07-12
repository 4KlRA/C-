#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    char arr [10][10];
    while(t--) {
        int score = 0;
        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) {
                cin >> arr[i-1][j-1];
            }
        }
        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) {
                if(arr[i-1][j-1] == 'X') {
                    if(i > 4 && j > 4 && i < 7 && j < 7) score += 5;
                    else if(i > 3 && j > 3 && i < 8 && j < 8) score += 4; 
                    else if(i > 2 && j > 2 && i < 9 && j < 9) score += 3;
                    else if(i > 1 && j > 1 && i < 10 && j < 10) score += 2; 
                    else score++;
                }
            }
        }
        cout << score << endl;
    }
    return 0;
}