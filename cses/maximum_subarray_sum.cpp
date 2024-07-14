#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

signed main(){
    int n; cin>>n; 
    vector<int> a(n);
    vector<int> asum(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(i==0) asum[i]=a[i];
        else asum[i] = asum[i-1]+a[i];
    }
    
    int maxsum = -1e9;
    vector<int> dp(n);
    dp[0] = min(asum[0],(int)0);
    maxsum = max(maxsum, asum[0]);
    for(int i = 1; i<n; i++){
        // if(i>0){
        dp[i] = min(dp[i-1], asum[i]);
        maxsum = max(maxsum, asum[i]-dp[i-1]);
        // }
        // for(int j = i; j<n; j++){
        //     int subsum;
        //     if(i == 0) subsum = asum[j];
        //     else subsum = asum[j]-asum[i-1];
        //     maxsum = max(maxsum, subsum);
        // }
    }
    cout<<maxsum<<endl;
}