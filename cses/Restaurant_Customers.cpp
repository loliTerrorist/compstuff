#include <bits/stdc++.h>
#define ll long long
using namespace std;    
int main(){
    int n;
    cin>>n;
    int maxs = 0;
    vector<pair<int, int> > vp;
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        vp.push_back({a, 1});
        vp.push_back({b,-1});

    }
    sort(vp.begin(), vp.end());
    int sum = 0;
    for(int i = 0; i<vp.size(); i++){
        sum+=vp[i].second;
        maxs = max(maxs, sum);
    }
    cout<<maxs<<endl;

}