#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
struct node{
    vector<int> cntnode;
};
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<node> graph(n);
        for(int i = 0; i<n-1; i++){
            int a, b; cin>>a>>b;
            graph[a].cntnode.push_back(b);
            graph[b].cntnode.push_back(a);
            
        }
        function<int(int,int)> dfs = [&](int nodeindex, int ignore){
            int size = 0;
            stack<int> s;
            vector<bool> visited(n, 0);
            s.push(nodeindex);
            while(!s.empty()){
                size++;
                int currindex = s.top();
                visited[currindex] = 1;
                s.pop();
                for(auto tt: graph[currindex].cntnode){
                    if(visited[tt]==0&&tt!=ignore){
                        s.push(tt);
                    }
                }
            }
            return size;
        };
        int center = n; int minmax = n;
        for(int i = 0; i<n; i++){
            vector<int> roots = graph[i].cntnode;
            int maxsize = 0;
            for(auto ctree: roots){
                maxsize = max(maxsize, dfs(ctree, i));
            }
            if(minmax==maxsize){
                center = min(center, i);
                minmax = maxsize;
            }else if(minmax>maxsize){
                minmax = maxsize;
                center = i;
            }
        }
        cout<<center<<endl;
    }
}