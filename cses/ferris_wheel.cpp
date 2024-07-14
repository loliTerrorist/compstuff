#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    int n, x; cin>>n>>x;
    vector<int> p(n); for(int i = 0; i<n; i++) cin>>p[i];
    sort(p.begin(), p.end());
    int l = 0; int r = n-1;
    int ans = 0;
    while(l<=r){
        if(p[r]+p[l]>x){
            r--;
            ans++;
        }else{
            r--; l++;
            ans++;
        }
    }
    cout<<ans<<endl;
}