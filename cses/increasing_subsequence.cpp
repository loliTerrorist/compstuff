#include <bits/stdc++.h>
#define int long long

using namespace std;
void printvec(vector<int> a){
    for(auto b: a){
        cout<<b<<' ';
    }cout<<endl<<endl;
}
signed main(){
    int n; cin>>n;
    vector<int> dp;
    //dp[x] = minimum ending value of an increasing subsequence of length x+1, 
    //using the elements considered so far
    vector<int> xs(n);
    for(int i = 0; i<n; i++){
        cin>>xs[i];
    }
    dp.push_back(xs[0]);
    for(int i = 1; i<n; i++){
        int index = -1;
        for(int j = dp.size(); j>=1; j/=2){
            while(index+j<dp.size()){
                if(dp[index+j]<xs[i]){
                    index+=j;
                }else{
                    break;
                }
            }
            
        }
        if(index==dp.size()-1){
            dp.push_back(xs[i]);
        }else{
            dp[index+1] = xs[i];
        }
        // printvec(dp);
    }
    cout<<dp.size()<<endl;
    
    
    
}