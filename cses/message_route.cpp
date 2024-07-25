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
    vector<int> visited(n+1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    // int steps = 0;
    // int counter = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(auto x: nodes[curr]){
            if(!visited[x]){
                q.push(x);
                visited[x] = visited[curr]+1;
            }
        }
        
        if(curr==n) break;
    }
    

    if(!visited[n]){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<visited[n]<<endl;
        vector<int> path; path.push_back(n);
        int counter = visited[n];
        int curr = n;
        while(counter-1){
            for(auto x: nodes[curr]){
                if(!visited[x]) continue;
                if(visited[x]==counter-1){
                    path.push_back(x);
                    curr = x;
                    counter--;
                    break;
                }
            }
        }

        for(int i = path.size()-1; i>=0; i--){
            cout<<path[i]<<" ";
        }
    }
    

}