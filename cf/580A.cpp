#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n);
    vector<int> dp(n,1);
    int maxn = 1;
    for(int i =0;i<n;i++){
        cin>>v[i];
        if(i>0){
            if(v[i]>=v[i-1]){
                dp[i] = dp[i-1]+1;
                maxn=max(maxn, dp[i]);
            }
        }
    }
    cout<<maxn<<endl;
    
}