#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> p(n);
    for(int i = 0; i<n; i++){
        cin>>p[i];
    }
    sort(p.begin(), p.end());
    int k = n/2;
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans += abs(p[i]-p[k]);
    }
    cout<<ans<<endl;
}