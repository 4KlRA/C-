#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.length() - 1 && count < 6; i++){
        if(s[i] == s[i + 1]){
            count++;
        } else {
            count = 0;
        }
    }
    if(count >= 6){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;   
    }
    return 0;
}