#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n; cin>>n;

    while(n--){
        int f; cin>>f;
        ll ans = 0;
        while(f--){
            ll area, num, level;
            cin>>area>>num>>level;
            ans+=area*level;
        }
        cout<<ans<<endl;
    }
}