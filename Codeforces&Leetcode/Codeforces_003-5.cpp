#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin  >> s;
    int count = 0; 

    for(int i = 0; i < s.length(); i++){
        if(s[i] == toupper(s[i])){
            count++;
        }
    }
    if(count > s.length() / 2){
        for(int i = 0; i < s.length(); i++){
            s[i] = toupper(s[i]);
        }
    }
    else{
        for(int i = 0; i < s.length(); i++){
            s[i] = tolower(s[i]);
        }
    }
    cout << s;
}