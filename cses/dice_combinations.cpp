#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> dp(1000001);
int main(){
    
    int mod = 1e9+7;
    int n; cin>>n;
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=6; j++){
            if(j>i) break;
            dp[i] = (dp[i]+dp[i-j])%mod;
        }
    }
    cout<<dp[n]<<endl;
    

}