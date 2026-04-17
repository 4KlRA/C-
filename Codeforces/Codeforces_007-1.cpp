#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int n;
    int p;
    cin >> n >> p;
    vector<int> a(p);
    for (int i = 0; i < p; i++){
        cin >> a[i];
    }
    cin >> p;
    vector<int> b(p);
    for(int i = 0; i < p; i++){
        cin >> b[i];
    }
    unordered_set<int> s;
    for (int i = 0; i < p; i++){
        s.insert(a[i]);
    }
    for(int i = 0; i < p; i++){
        s.insert(b[i]);
    }
    if(s.size() == n){
        cout << "I become the guy." << endl;
    }
    else{
        cout << "Oh, my keyboard!" << endl;
    }
    return 0;
}