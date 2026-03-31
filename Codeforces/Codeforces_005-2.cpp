#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1;
    for(int i = 0; i < s1.length(); i++){
        char c = tolower(s1[i]);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'){
            continue;
        } else{
            s2.append("." + string(1, tolower(s1[i])));
        }
    }
    cout << s2 << endl;
    return 0;
}