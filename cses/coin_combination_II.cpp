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
    
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=x; j++){
            if(j-c[i]<0) continue;

            dp[j] = (dp[j]+dp[j-c[i]])%mod;
            
        }
    }
    cout<<dp[x]<<endl;
}