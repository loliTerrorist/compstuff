#include <bits/stdc++.h>
#define int long long

using namespace std;
void printvec(vector<int> a){
    for(auto aa: a){
        cout<<aa<<' ';
    }cout<<endl;
}
signed main(){
    int n, m, k; cin>>n>>m>>k;
    vector<vector<int> > graph(n+1);
    set<int> wormholes;
    for(int i = 0; i<k; i++){
        int temp; cin>>temp;
        wormholes.insert(temp);
    }
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> start_distance(n+1, 1e9);
    vector<int> goal_distance(n+1, 1e9);
    start_distance[1] = 0;
    goal_distance[n] = 0;
    if(1){
        vector<bool> visited(n+1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while(!q.empty()){
            int currnode = q.front();
            q.pop();
            for(auto node: graph[currnode]){
                if(visited[node]==0){
                    q.push(node);
                    visited[node] = 1;
                    start_distance[node] = start_distance[currnode]+1;
                }
            }   
        }
    }
    if(1){
        vector<bool> visited(n+1, 0);
        queue<int> q;
        q.push(n);
        visited[n] = 1;
        while(!q.empty()){
            int currnode = q.front();
            q.pop();
            for(auto node: graph[currnode]){
                if(visited[node]==0){
                    q.push(node);
                    visited[node] = 1;
                    goal_distance[node] = goal_distance[currnode]+1;
                }
            }   
        }
    }
    // printvec(start_distance);
    int ans2 = 1e9;
    int dsum = 0;
    for(auto node: wormholes){
        dsum += goal_distance[node];
    }
    for(auto node: wormholes){
        ans2 = min(ans2, (start_distance[node]*(k-1)+dsum-goal_distance[node]));
    }
    
    if((double)start_distance[n]<=(double)ans2/(double)(k-1)){
        cout<<start_distance[n]<<"/1"<<endl;
    }else{
        int g = __gcd(ans2, k-1);
        int newchild = ans2/g;
        int newmom = (k-1)/g;
        // int newchild = 6;
        // int newmom = 3;
        // int g = __gcd(newchild, newmom);
        // newchild = newchild/g;
        // newmom = newmom/g;
        cout<<newchild<<"/"<<newmom<<endl;
    

    }
}