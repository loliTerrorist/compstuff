#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back


using namespace std;

int main(){
    cin.tie(0);
    int n; 
    vector<vector<int> > graph;
    vector<int> distance;
    function<void(int)> dfs = [&](int a){
        for(auto c: graph[a]){
            if(distance[c] == -1){
                distance[c]=distance[a]+1;
                dfs(c);
            } 
        }
    };
    while(cin>>n){
        graph.assign(n, {});
        for(int i = 0; i<n-1; i++){
            int a, b; cin>>a>>b;
            graph[a].pb(b); graph[b].pb(a);
        }

        distance.assign(n, -1);
        
        dfs(0);
        int maxdis20 = 0; int maxdis20i;
        for(int i = 0; i<n; i++){
            if(maxdis20<distance[i]){
                maxdis20 = distance[i];
                maxdis20i = i;
            }
        }
        for(int i = 0; i<n; i++){
            distance[i] = -1;
        }
        distance[maxdis20i] = 0;
        dfs(maxdis20i);
        int maxdis = 0; 
        for(int i = 0; i<n; i++){
            if(maxdis<distance[i]){
                maxdis = distance[i];
            }
        }
        cout<<maxdis<<endl;
    }
}