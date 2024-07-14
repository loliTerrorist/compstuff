#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){

    int n, t; cin>>n>>t;
    vector<int> machines(n);
    int maxspeed = 1e9;
    for(int i = 0; i<n; i++){
        cin>>machines[i];
        maxspeed = min(machines[i], maxspeed);
    }
    int r = t*maxspeed;
    int l = 0;
    int ans;
    while(l<=r){
        int m = (l+r)/2;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=m/machines[i];
            if(sum>=t) break;
        }
        if(sum>=t){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout<<ans<<endl;
    
    
}