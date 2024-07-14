#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<char> moves = {'D','U','R','L'};
signed main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<string> inmap(n);
    for(int i = 0; i<n; i++){
        cin>>inmap[i];
    }
    int ax = 0; int ay = 0; int bx = 0; int by = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(inmap[i][j]=='A'){
                ax = i; ay = j;
            }
            if(inmap[i][j]=='B'){
                bx=i; by=j;
            }
        }
    }
    vector<vector<bool> > visited(n, vector<bool>(m));
    vector<vector<char> > movement(n, vector<char>(m, '#'));
    queue<pair<int,int> > tovisit;
    bool found = 0;
    auto checkx = [&](int a){
        if(a>=0&&a<n) return true;
        else return false;
    };
    auto checky = [&](int a){
        if(a>=0&&a<m) return true;
        else return false;
    };
    tovisit.push({ax,ay});
    while(!tovisit.empty()){
        int currx = tovisit.front().first;
        int curry = tovisit.front().second;
        visited[currx][curry] = 1;
        if(currx==bx&&curry==by){
            found=1; break;
        }
        tovisit.pop();
        for(int i = 0; i<4; i++){
            int sx = currx+dx[i]; int sy = curry+dy[i];
            if(checkx(sx)&&checky(sy)&&visited[sx][sy]==0&&inmap[sx][sy]!='#'){
                // cout<<sx<<' '<<sy<<endl;
                tovisit.push({sx,sy});
                visited[sx][sy]=1;
                movement[sx][sy] = moves[i];
                if(currx==bx&&curry==by){
                    found=1; break;
                }
            }
        }
    }
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<movement[i][j];
    //     }
    //     cout<<endl;
    // }
    if(found){
        cout<<"YES"<<endl;
        vector<char> revmoves;
        int currx = bx; int curry = by;
        while(currx!=ax||curry!=ay){
            switch(movement[currx][curry]){
                case 'D':
                revmoves.push_back('D');
                    currx-=dx[0];
                    curry-=dy[0];
                    break;
                case 'U':
                revmoves.push_back('U');
                    currx-=dx[1];
                    curry-=dy[1];
                    break;
                case 'R':
                revmoves.push_back('R');
                    currx-=dx[2];
                    curry-=dy[2];
                    break;
                case 'L':
                    revmoves.push_back('L');
                    currx-=dx[3];
                    curry-=dy[3];
                    break;
            }
        }
        cout<<revmoves.size()<<endl;
        for(int i = revmoves.size()-1; i>=0; i--){
            cout<<revmoves[i];
        }
    }else{
        cout<<"NO"<<endl;
    }



    
}