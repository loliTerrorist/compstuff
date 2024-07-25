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

    string a, b;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    /*
    dp[i][j] records the min steps required to make first i letters of a and first j of b equal
    
    Say we have dp[i-1][j-1], dp[i-1][j], dp[i][j-1]
    
    we have a few options:
        1. Follow how we made the first i, j-1 th char the same and just remove the j th
            dp[i][j] = dp[i][j-1]+1
        2. Same as 1. but with i
            dp[i][j] = dp[i-1][j]+1
        3. Make the first i-1, j-1 th char the same, change the ith(or jth) letter
            dp[i][j] = dp[i-1][j-1]+1
        4. Same as above, but a[i-1]=b[j-1] so we don't change the ith(or jth) letter
            dp[i][j] = dp[i-1][j-1]


    */
    vector<vector<int> > dp(n+1, vector<int>(m+1, 1e9));
    dp[0][0] = 0;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(i){
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
            }
            if(j){
                dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
            }
            if(i&&j){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+!(a[i-1]==b[j-1]));
            }
        }
    }
    // printvec(dp);
    cout<<dp[n][m]<<endl;
    

}

