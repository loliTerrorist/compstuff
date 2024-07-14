#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> k(n); for(int i = 0; i<n; i++) cin>>k[i];
    multiset<int> tops;
    for(int i = 0; i<n; i++){
        auto it = tops.upper_bound(k[i]);
        if(it == tops.end()){
            tops.insert(k[i]);
        }else{
            tops.erase(it);
            tops.insert(k[i]);
        }
    }
    cout<<tops.size()<<endl;
}