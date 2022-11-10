#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
using namespace std;
vector<pair<int,int> > dif = {{1,0},{0,1},{-1,0},{0,-1}};
int n;
pair<bool, int> bfs(vector<vector<int> > &v, int limit){
    queue<pair<int, int> > q;
    vector<vector<int> > visited(n, vector<int>(n, 0));
    vector<vector<int> > dis(n, vector<int> (n, 0));
    q.push({0,0});
        while(!q.empty()){
            int x = q.front().first; int y = q.front().second;
            for(pair<int,int> &difp: dif){
                if(x+difp.first>=0&&x+difp.first<n&&y+difp.second>=0&&y+difp.second<n){
                    if(!visited[x+difp.first][y+difp.second]&& (abs(v[x+difp.first][y+difp.second]-v[x][y])<=limit) ){
                        q.push({x+difp.first,y+difp.second});
                        visited[x+difp.first][y+difp.second] = 1;
                        dis[x+difp.first][y+difp.second] = dis[x][y]+1;
                    }
                }
            }
            q.pop();

        }
        return pair<bool, int> ({visited[n-1][n-1], dis[n-1][n-1]});
}
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin>>n;
    int maxnum = 0;
    vector<vector<int> > v(n, vector<int>(n));
    vector<vector<bool> > visited(n, vector<bool>(n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>v[i][j];
            maxnum = max(maxnum, v[i][j]);
        }
    }
    int l = 0; int r = 1e6-1;
    while(l!=r){
        int m = (r+l)/2;
        if(bfs(v, m).first){
            r = m;
        }else{
            l=m+1;
        }
    }

    cout<<l<<endl;
    cout<<bfs(v,l).second<<endl;
    
    // int kk = 0;
    // int dis = 0;
    // while(kk<=maxnum){
    //     //bfs
    //     if(bfs(v, kk).first){
    //         break;
    //     }else{
    //         kk++;
    //     }
    // }
    // dis = bfs(v, kk).second;
    // cout<<kk<<endl;
    // cout<<dis<<endl;
}