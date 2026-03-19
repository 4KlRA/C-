#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    int count = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i < n; i++){
        if(s[i-1] == s[i]){
            count += 1;
        }
    }
    cout << count << endl;
}