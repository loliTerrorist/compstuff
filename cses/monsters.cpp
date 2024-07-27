#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


signed main(){
    int n, m; cin>>n>>m;
    vector<string> labyrinth(n);
    for(int i = 0; i<n; i++){
        cin>>labyrinth[i];
    }
    // cout<<(labyrinth[0][0]=='#')<<endl;
    set<pair<int, int> > monster_pos;
    pair<int, int> my_pos;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){

            pair<int, int> curr_pos(i,j);
            switch (labyrinth[i][j])
            {
            case 'M':
                monster_pos.insert(curr_pos);
                break;
            case 'A':
                my_pos = curr_pos;
                break;
            default:
                break;
            }
        }
    }
    /*
    We first get where all the monsters are at, and the player position
    We keep 2 kinds of visited vector, 1 for monsters and one for players
    for monsters:
        starting from a monster, we bfs outward, recording at this position, how many steps does a monster have to take
        so we start with a monster, when we visit a new pos, we update the pos's visited with the smallest step
        pos where the monster start will remain as 0
        When moving, we just need to check if out destination is within bounds and empty
        
    for players: 
        When moving, keep track of our steps, we can only move to a pos whose monsters' step is higher than ours
        
    our visit function should take in:
        1. the coordinate we're moving to
        2. what we are(mon or human)
    our visit function should:
        1. mark the coordinate as visited with the right number of steps
        2. push the coordinate into queue
    
    */
    queue<pair<int, int> > q;
    vector<vector<int> > mon_visited(n, vector<int>(m));
    vector<vector<int> > human_visited(n, vector<int>(m));
    
    auto mon_visit = [&](int i, int j, int step){
        if(i>=n||j>=m||i<0||j<0||labyrinth[i][j]=='#'){
            
        }else{
            if((mon_visited[i][j]==0||mon_visited[i][j]>=step)&&!monster_pos.count(pair<int, int>(i,j))){
                mon_visited[i][j] = step;
                q.push(pair<int, int>(i, j));
            }
        }
    };
    auto human_visit = [&](int i, int j, int step){
        if(i<0||i>=n||j>=m||j<0||labyrinth[i][j]=='#'){
            
        }else{
            if(mon_visited[i][j]>=step&&human_visited[i][j]==0){
                human_visited[i][j] = step;
                q.push(pair<int, int>(i, j));
            }
        }
    };
    for(auto mp: monster_pos){
        q.push(mp);
        int step = 0;
        while(!q.empty()){
            
            pair<int, int> currpos = q.front();
            q.pop();
            step++;
            for(int i = 0; i<4; i++){
                switch (i)
                {
                case 0:
                    mon_visit(currpos.first-1, currpos.second, step);
                    /* code */
                    break;
                case 1:
                    mon_visit(currpos.first, currpos.second+1, step);
                    break;
                case 2: 
                    mon_visit(currpos.first+1, currpos.second, step);
                    break;
                case 3: 
                    mon_visit(currpos.first, currpos.second-1, step);
                default:
                    break;
                }
            }
            for (auto aaa: mon_visited){
                for(auto aaaa: aaa){
                    cout<<aaaa;
                }cout<<endl;
            }cout<<endl;
        
        }
    }
    vector<vector<char> > prev(n, vector<char>(m));
    q.push(my_pos);
    int step = 0;
    pair<int, int> destination;
    bool ok = 0;
    while (!q.empty()) {
        
        step++;
        pair<int, int> currpos = q.front();
        if(currpos.first==0||currpos.first==n-1||currpos.second==0||currpos.second==m-1){
            destination = currpos;
            ok = 1;
            break;
        }
        q.pop();
        for(int i = 0; i<4; i++){
                switch (i)
                {
                case 0:
                    human_visit(currpos.first-1, currpos.second, step);
                    prev[currpos.first-1][currpos.second] = 'U';
                    break;
                case 1:
                    human_visit(currpos.first, currpos.second+1, step);
                    prev[currpos.first][currpos.second+1] = 'R';
                    break;
                case 2: 
                    human_visit(currpos.first+1, currpos.second, step);
                    prev[currpos.first+1][currpos.second] = 'D';
                    break;
                case 3: 
                    human_visit(currpos.first, currpos.second-1, step);
                    prev[currpos.first][currpos.second-1] = 'L';
                    break;
                default:
                    break;
                }
            
        }
    }
    if(ok){
    vector<char> route;
    pair<int, int> currpos = destination;
    while(currpos!=my_pos){
        route.push_back(prev[currpos.first][currpos.second]);
        switch(prev[currpos.first][currpos.second]){
            case 'U':
                currpos.first++;
                break;
            case 'R':
                currpos.second--;
                break;
            case 'D':
                currpos.first--;
                break;
            case 'L':
                currpos.second++;
                break;
            default:
                break;
            
        }
    }
    cout<<"OK"<<endl;
    cout<<route.size()<<endl;
    for(int i = route.size()-1; i>=0; i--){
        cout<<route[i]<<" ";
    }
    }else{
        cout<<"NO"<<endl;
    }
}