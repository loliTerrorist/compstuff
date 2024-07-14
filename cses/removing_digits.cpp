#include <bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;

vector<int> int2vec(int n){
    vector<int> ret;
    int highpower = 0;
    int temp = 1;
    for(; temp<n; highpower+=1, temp*=10);
    if(temp!=n){
        temp/=10; highpower--;
    }
    for(; highpower>=0; temp/=10, highpower--){
        ret.push_back(n/temp);
        n = n - (n/temp)*temp;
    }
    return ret;
}

signed main(){
    int n; cin>>n;
    vector<int> dp(n+1, -1);
    function<int(int)> find = [&](int x){
        if(dp[x]!=-1) return dp[x];
        else{
            if(x<10){
                dp[x] = 1;
                return dp[x];
            }else{
                vector<int> xvec = int2vec(x);
                for(int i = xvec.size()-1; i>=0; i--){
                    if(xvec[i]!=0){
                        if(dp[x]==-1) dp[x] = 1+find(x-xvec[i]);
                        else dp[x] = min(dp[x], 1+find(x-xvec[i]));
                    }
                }
                
            }
        }
        return dp[x];
    };
    cout<<find(n)<<endl;
}