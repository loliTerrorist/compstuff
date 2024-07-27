#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int t; cin>>t;
    vector<int> ns(t);    
    int maxn = 0;
    for(int i = 0; i<t; i++){
        cin>>ns[i];
        maxn = max(maxn, ns[i]);
    }
    vector<int> an(maxn+1); an[1] = 1;
    vector<int> bn(maxn+1); bn[1] = 1;
    int mod = 1e9+7;
    vector<vector<int> > matrix = {{2, 1},{1,4}};
    function<vector<vector<int> >(vector<vector<int> >,vector<vector<int> >) > mult = [&](vector<vector<int> > am, vector<vector<int> > bm){
        vector<vector<int> > output = {
            {(am[0][0]*bm[0][0]%mod+am[0][1]*bm[1][0]%mod)%(mod), (am[0][0]*bm[0][1]%mod+am[0][1]*bm[1][1]%mod)%mod},
            {(am[1][0]*bm[0][0]%mod+am[1][1]*bm[1][0]%mod)%mod, (am[1][0]*bm[0][1]%mod+am[1][1]*bm[1][1]%mod)%mod}
        };
        return output;
    };
    // function<vector<int>(vector<vector<int> >, vector<int>) > mult = [&](vector<vector<int> > mata, vector<int> matb){
    //     vector<int> ans = {
    //         (mata[0][0]*matb[0]%mod+mata[0][1]*matb[1]%mod)%mod,
    //         (mata[1][0]*matb[1]%mod+mata[1][1]*matb[1]%mod)%mod
    //     };
    //     return ans;
    // };
    function<vector<vector<int> >(vector<vector<int> >, int) > matpow = [&](vector<vector<int> > mat, int power){
        if(power==1){
            return mat;
        }else{
            int apower = power/2;
            int bpower = power-apower;
            vector<vector<int> > ans = (mult(matpow(mat, apower), matpow(mat, bpower)));
            return ans;
        }
    };
    for(int i = 2; i<=maxn; i++){
        an[i] = 2*an[i-1]%mod+bn[i-1]%mod;
        bn[i] = an[i-1]%mod+4*bn[i-1]%mod;
    }
    // vector<vector<int>(int)> find = [&](int a){
    //     if(an[a]!=0&&bn[a]!=0){
    //         return vector<int>{an[a], bn[a]};
    //     }else{
    //         vector<vector<int> > ans = matpow(matrix, a-1);
            
    //     }
    // };
    for(auto nns: ns){
        if(nns==1){
            cout<<2<<endl;
            continue;
        }
        // vector<vector<int> > ans = matpow(matrix, nns-1);
        cout<<(an[nns]+bn[nns])%mod<<endl;
    }
}