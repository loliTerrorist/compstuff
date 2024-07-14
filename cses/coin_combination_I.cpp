#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int n, x; cin>>n>>x;
    int mod = 1e9+7;
    vector<int> c(n);
    vector<int> dp(x+1);
    for(int i = 0; i<n; i++){
        cin>>c[i];
    }
    dp[0] = 1;
    for(int i = 1; i<=x; i++){
        for(int j = 0; j<n; j++){
            if(i-c[j]<0) continue;
            dp[i] = (dp[i]+dp[i-c[j]])%mod;
        }
    }
    cout<<dp[x]<<endl;
}