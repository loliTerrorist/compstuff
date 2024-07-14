#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int n; cin>>n;
    vector<int> x(n);
    
    for(int i = 0; i<n; i++) {
        int temp; cin>>temp;
        x[i] = temp;
    }

    
    sort(x.begin(), x.end());
    int ans = 1;
    for(int i = 0; i<n&&x[i]<=ans; i++){
        ans += x[i];
    }
    cout<<ans<<endl;
    
}