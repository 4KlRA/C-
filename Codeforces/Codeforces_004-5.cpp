#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int UniqueYear(int n) {
    unordered_set<int> distinctDigits;
    int count = 0;
    while (n > 0) {
        int digit = n % 10;          
        distinctDigits.insert(digit); 
        n /= 10;  
        count++;                   
    }
    if (distinctDigits.size() == count) {
        return 1;
    }
    return 0;
}


int main(){
    int num;
    cin >> num;
    while (true) {
        num++;
        if (UniqueYear(num)) {
            cout << num << endl;
            break;
        }
    }
    return 0;
}