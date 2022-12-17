#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int> 
#define endl "\n"

using namespace std;
// bool dfs(vector<vector<int> > &grid, int ai, int bi, int limit){
    
//     if(ai==grid.size()-1&&bi==grid[0].size()-1){
//         return 1;
//     }
//     bool ans = 0;
//     int max1, max2;
//     if(ai+1<grid.size()){
//         if(grid[ai+1][bi]<=limit&&grid[ai+1][bi]>=0){

//             ans = dfs(grid, ai+1, bi, limit)||ans;
//         }
        
//     }
//     if(bi+1<grid[0].size()){
//         if(grid[ai][bi+1]<=limit&&grid[ai][bi+1]>=0){

//             ans = dfs(grid, ai, bi+1, limit)||ans;
//         }
        
//     }
//     return ans;
// }
bool bfs(vector<vector<int> > &v, int limit){
    queue<pair<int, int> > q;
    vector<vector<int> > visited(v.size(), vector<int>(v[0].size(), 0));
    vector<pair<int, int> > dif={{1,0},{0,1}};
    q.push({0,0});
        while(!q.empty()){
            int x = q.front().first; int y = q.front().second;
            for(pair<int,int> &difp: dif){
                if(x+difp.first<v.size()&&y+difp.second<v[0].size()){
                    if(!visited[x+difp.first][y+difp.second]&& v[x+difp.first][y+difp.second]<=limit&&v[x+difp.first][y+difp.second]>=0){
                        q.push({x+difp.first,y+difp.second});
                        visited[x+difp.first][y+difp.second] = 1;
                    }
                }
            }
            q.pop();

        }
        return visited[v.size()-1][v[0].size()-1];
}
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<int> as(n);
    vector<int> bs(m);
    for(int i = 0;i<n;i++){
        cin>>as[i];
    }
    for(int i = 0; i<m; i++){
        cin>>bs[i];
    }
    vector<vector<int> > grid(n+1,vector<int>(m+1, 0));
    int gridmax = 0;
    //build grid
    for(int i = 0; i<=n; i++){
        if(i!=0) grid[i][0] = as[i-1]+grid[i-1][0];
        for(int j = 0; j<=m; j++){
            if(j!=0) grid[i][j] = bs[j-1]+grid[i][j-1];
            gridmax = max(gridmax, grid[i][j]);
            // cout<<(grid[i][j])<<" ";
        }
        // cout<<endl;
        
    }

    int l = 0; int r = gridmax;
    while(l!=r){
        int m = (l+r)/2;
        if(bfs(grid, m)){
            r = m;
        }else{
            l = m+1;
        }
    }
    if(bfs(grid,l)){

        cout<<l<<endl;
    }else{
        cout<<-1<<endl;
    }

    


}



