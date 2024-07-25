#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int> > nodes(n+1);
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    queue<int> q;
    vector<int> visited(n+1);
    q.push(1);

}