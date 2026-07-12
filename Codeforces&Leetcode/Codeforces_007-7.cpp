#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, faces = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if (s == "Icosahedron") faces += 20;
        else if (s == "Cube") faces += 6;
        else if (s == "Tetrahedron") faces += 4;
        else if (s == "Octahedron") faces += 8;
        else faces += 12;
    }
    cout << faces;
    return 0;
}