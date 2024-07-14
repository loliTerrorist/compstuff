#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int> > prices(n);
    for(int i = 0; i<n; i++){
        for(int i = 0; i<min(m, n-i+1)+1; i++){
            int a; cin>>a;
            prices[i].push_back(a);
        }
    }
    int cost = 0;
    

}