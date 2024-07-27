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
    bool ans = 1;
    stack<int> s;
    vector<int> visited(n+1);
    set<int> unvisited;
    for(int i = 1; i<=n; i++){
        unvisited.insert(i);
    }
    
    while(!unvisited.empty()){
        int start = *unvisited.begin();
        unvisited.erase(start);
        visited[start] = 1;
        s.push(start);
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            for(auto e: nodes[curr]){
                if(visited[e]){
                    if(visited[curr]==visited[e]){
                        ans=0; break;
                    }
                }else{
                    visited[e] = 1+!(visited[curr]-1);
                    unvisited.erase(e);
                    s.push(e);
                }
            }
        }
    }

    if(!ans){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(int i = 1; i<=n; i++){
            cout<<visited[i]<<" ";
        }
    }

}