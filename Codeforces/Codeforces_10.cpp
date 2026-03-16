#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v;
    for(int i = 0; i < n; i++){
        if (s[i] == '+'){
            continue;
        }
        else{
            v.push_back(s[i] - '0');
        }
    }
    for(int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size() - i - 1; j++){
            if (v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < v.size() - 1; i++){
        cout << v[i] << "+";
    }
    cout << v[v.size()-1] << endl;
return 0;
}