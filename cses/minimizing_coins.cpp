#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main(){
    int n, x; cin>>n>>x;
    vector<int> cs(n);
    for(int i = 0; i<n; i++){
        cin>>cs[i];
    }
    vector<int> dp(x+1, 1000001);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j<n; j++){
            if(i-cs[j]<0) continue;
            dp[i] = min(dp[i], dp[i-cs[j]]+1);
            // if(i==1000) cout<<j<<' '<<dp[i]<<endl;
        }
    }
    if(dp[x]==1000001){
        cout<<-1<<endl;
    }else{
        cout<<dp[x]<<endl;
    }
    
}