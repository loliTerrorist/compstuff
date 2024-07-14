#include <bits/stdc++.h>
#define int long long

using namespace std;
void printvec(vector<vector<int> > a){
    for(auto i: a){
        for(auto j: i){
            cout<<j<<' ';
        }cout<<endl;
    }
    cout<<endl;
}
signed main(){
    int n, m; cin>>n>>m;
    vector<int> arr(n);
    vector<int> unknown_index;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int mod = 1e9+7;
    vector<vector<int> > dp(n, vector<int>(m+1, 0));
    //dp[i][j] records the number of ways to fill up until arr[i] when arr[i] = j
    if(arr[0] == 0){
        for(int i = 1; i<=m; i++){
            dp[0][i] = 1;
        }
    }else{
        dp[0][arr[0]] = 1;
    }

    for(int i = 1; i<n; i++){
        if(arr[i]==0){
            for(int j = 1; j<=m; j++){
                for(int k: {j-1, j, j+1}){
                    if(k>=1&&k<=m){
                        (dp[i][j] += dp[i-1][k]) %= mod;
                        // printvec(dp);
                    }
                }
            }
        }else{
            for(int k: {arr[i]-1, arr[i], arr[i]+1}){
                if(k>=1&&k<=m){
                    (dp[i][arr[i]] += dp[i-1][k]) %= mod;
                    // printvec(dp);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<=m; i++){
        ans = (ans+dp[n-1][i])%mod;
    }
    cout<<ans<<endl;
    
    
}