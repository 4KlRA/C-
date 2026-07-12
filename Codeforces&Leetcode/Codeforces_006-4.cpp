#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> color;
    for(int i = 0; i < 4; i++){
        int c;
        cin >> c;
        color.insert(c);
    }
    cout << 4 - color.size();
    return 0;
}