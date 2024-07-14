#include <bits/stdc++.h>
#define int long long

using namespace std;
void printvec(vector<vector<int> > a){
    for(auto aa: a){
        for(auto aaa: aa){
            cout<<aaa<<' ';
        }cout<<endl;
    }cout<<endl;
}
signed main(){
    int i, j; i = j = 0;
    string a, b; cin>>a>>b;
    int n, m; 
    n = a.size(); m = b.size();
    vector<vector<int> > dp(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        if(a[i]==b[0]){
            dp[i][0] = 1;
        }
        if(i!=0){
            dp[i][0] = max(dp[i][0], dp[i-1][0]);
        }
    }
    for(int i = 0; i<m; i++){
        if(a[0]==b[i]){
            dp[0][i] = 1;
        }
        if(i!=0){
            dp[0][i] = max(dp[0][i], dp[0][i-1]);
        }
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<m-dp[n-1][m-1]<<endl;

}