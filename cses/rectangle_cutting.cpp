#include <bits/stdc++.h>
#define int long long
using namespace std;

void printvec(vector<vector<int> > a){
    for(auto aa:a){
        for(auto aaa:aa){
            cout<<aaa<<' ';
        }cout<<endl;
    }cout<<endl;
}
signed main(){
    int a, b; cin>>a>>b;
    int temp = a;
    a = min(temp, b);
    b = max(temp, b);
    //dp[short][long]
    vector<vector<int> > dp(a+1, vector<int>(b+1, 0));
    function<int(int, int)> find = [&](int w, int h){
        int ans = w*h+1;
        if(w == h) return (int)0;
        else if(dp[w][h]!=0){
            return dp[w][h];
        }else{
            for(int i = 1; i<w; i++){
                ans = min(ans, 1+find(min(w-i, h), max(w-i, h))+find(min(i, h), max(i, h)));
                dp[w][h] = ans;
                // printvec(dp);
            }
            for(int i = 1; i<h; i++){
                ans = min(ans, 1+find(min(w, h-i), max(w, h-i))+find(min(w, i), max(w, i)));
                dp[w][h] = ans;
                // printvec(dp);
            }
            
        }
        
        
        return dp[w][h];

    };
    cout<<find(a, b)<<endl;



}