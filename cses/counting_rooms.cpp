#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){

    int n, m; cin>>n>>m;
    vector<string> inmap(n);
    for(int i = 0; i<n; i++){
        cin>>inmap[i];
    }
    vector<int> deltax = {1,-1,0,0};
    vector<int> deltay = {0,0,1,-1};
    vector<vector<bool> > visited(n,vector<bool>(m));
    int roomcount = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(inmap[i][j]=='.'&&visited[i][j]==0){
                roomcount++;
                stack<pair<int,int> > points;
                points.push({i,j});
                while(!points.empty()){
                    
                    int currx = points.top().first;
                    int curry = points.top().second;
                    if(currx<0||currx>n-1||curry<0||curry>m-1){
                        points.pop(); continue;
                    }
                    if(visited[currx][curry]==1){
                        points.pop();
                        continue;
                    }
                    points.pop();
                    visited[currx][curry]=1;
                    if(inmap[currx][curry]=='.'){
                        for(int k = 0; k<4; k++){
                            points.push({currx+deltax[k], curry+deltay[k]});
                        }
                    }
                    
                }
            }
        }
    }
    cout<<roomcount<<endl;

}