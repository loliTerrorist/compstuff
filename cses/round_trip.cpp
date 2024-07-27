#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int> > roads(n+1);
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    vector<int> prev(n+1);
    stack<int> s;
    //I should probably just ditch visited but meh
    vector<int> visited(n+1);
    set<int> unvisited;
    for(int i = 1; i<=n; i++){
        unvisited.insert(i);
    }
    int start = 0;
    bool ok = 0;
    while(!unvisited.empty()&&!ok){
        s.push(*unvisited.begin());
        visited[*unvisited.begin()] = 1;
        unvisited.erase(*unvisited.begin());
    
        while(!s.empty()&&!ok){
            
            int curr = s.top();
            s.pop();
            for(auto v: roads[curr]){
                if(visited[v]){
                    if(prev[curr]==v){
                        continue; //Since we only have at most one road between two cites, we can't walk back to the city we came from
                    }else{
                        start = v;
                        prev[prev[v]] = v;
                        prev[v] = curr;
                        ok = 1;
                        break;
                    }
                }else{
                    s.push(v);
                    unvisited.erase(v);
                    visited[v] = 1;
                    prev[v] = curr;
                }
            }
        }
    }
    if(ok){
        
        int f = prev[start];
        vector<int> route;
        route.push_back(start);
        while(f!=start){
            route.push_back(f);
            if(prev[f]==0){
                prev[f] = start;
                
            }
            f = prev[f];
            
        }
        route.push_back(f);
        cout<<route.size()<<endl;
        for(auto r: route){
            cout<<r<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }



}