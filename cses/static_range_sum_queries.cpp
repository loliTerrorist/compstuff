#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    int n, q;
    cin>>n>>q;
    vector<int> prefix_sum(n+1);
    for(int i = 1; i<=n; i++){
        
        cin>>prefix_sum[i];
        prefix_sum[i]+=prefix_sum[i-1];
       
    }
    for(int i = 0; i<q; i++){
        int a, b; cin>>a>>b;
        
        cout<<prefix_sum[b]-prefix_sum[a-1]<<endl;
    }

}