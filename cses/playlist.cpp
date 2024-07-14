#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> k(n); for(int i =0; i<n; i++){cin>>k[i];}
    map<int,int> index;
    int ans = 0;
    for(int i = 0, j = 0; i<n; i++){
        j = max(index[k[i]],j);
        ans = max(i-j+1, ans);
        index[k[i]] = i+1;
    }
    cout<<ans<<endl;
}