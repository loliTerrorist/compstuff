#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int t; cin>>t;
    vector<int> ns(t);    
    int maxn = 0;
    for(int i = 0; i<t; i++){
        cin>>ns[i];
        maxn = max(maxn, ns[i]);
    }
    vector<int> dp(maxn+1);
    

}