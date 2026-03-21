#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            count++;
        }
        else if(s[i] == 'D'){
            count--;
        }
    }
    if(count > 0){
        cout << "Anton" << endl;
    }
    else if(count < 0){
        cout << "Danik" << endl;
    }
    else{
        cout << "Friendship" << endl;
    }
    return 0;
}