#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    int n, q; cin>>n>>q;
    vector<int> arr(n+1);
    vector<int> pref_xor(n+1);
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
        pref_xor[i] = pref_xor[i-1]^arr[i];
    }
    for(int i =0 ; i<q; i++){
        int a, b; cin>>a>>b;
        int ans = pref_xor[a-1]^pref_xor[b];
        cout<<ans<<endl;
    }
}