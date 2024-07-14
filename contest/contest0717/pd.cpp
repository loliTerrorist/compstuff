#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, h, w;
    cin >> n >> h >> w;
    for(int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        if(a == 'Y' || w == 0) {
            h--;
            w++;
            cout << "Y ";
        }else {
            cout << "N ";
        }
        if(b == 'Y' || h == 0) {
            w--;
            h++;
            cout << "Y\n";
        }else {
            cout << "N\n";
        }
    }
}