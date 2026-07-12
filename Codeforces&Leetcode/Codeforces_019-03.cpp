#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, a, one = 0, two = 0, three = 0;
    cin >> t;
    vector<int> stud;
    while(t--) {
        cin >> a;
        stud.push_back(a);
        if(a == 1) one++;
        else if(a == 2) two++;
        else three++;
    }
    int mx = min(one, two);
    mx = min(mx, three);
    cout << mx << endl;
    while(mx--) {
        bool o = true, t = true, th = true;
        for(int i = 0; i < stud.size() && (o || t || th) ; i++) {
            if(o && stud[i] == 1) {
                cout << i+1 << " ";
                stud[i] = 0;
                o = false;
            } else if(t && stud[i] == 2) {
                cout << i+1 << " ";
                stud[i] = 0;
                t = false;
            } else if(th && stud[i] == 3) {
                cout << i+1 << " ";
                stud[i] = 0;
                th = false;
            }
        }
        cout << endl;
    }
    return 0;
}