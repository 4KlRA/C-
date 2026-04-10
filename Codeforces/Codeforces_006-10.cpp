#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for(char c : s){
        if(c == 'H' || c == 'Q' || c == '9'){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}