#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    int x, n; cin>>x>>n;
    vector<int> p(n); for(int i = 0; i<n;i++){
        cin>>p[i];
    }
    set<int> points;
    multiset<int> segments;
    segments.insert(x);
    points.insert(0); points.insert(x);
    for(auto pp: p){
        int ans = 0;
        auto itr = points.lower_bound(pp);
        auto itl = itr;
        itl--;
        segments.erase(segments.find(*itr-*itl));
        segments.insert(*itr-pp);
        segments.insert(pp-*itl);
        points.insert(pp);
        ans = *segments.rbegin();
        cout<<ans<<endl;
    }

    
    
        
    
   
}