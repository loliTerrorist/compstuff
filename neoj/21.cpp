#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
struct player{
    int rank; int id; int nextplayer; int prevplayer;
};
signed main(){
    int n; cin>>n;
    int m; cin>>m;
    vector<player> players(n+1);
    players[0].id = 0;
    players[0].rank = 0;
    players[0].nextplayer = 1;
    for(int i = 1; i<=n; i++){
        if(i==n){
            players[i].nextplayer = 0;
        }else{
            players[i].nextplayer = i+1;
        }
        players[i].prevplayer = i-1;
        players[i].id = i;
        players[i].rank = i;
    }
    for(int mm = 0; mm<m; mm++){
        // cout<<endl<<mm+1<<endl;
        int t, x; cin>>t>>x;
        
        if(t==0){
            int thisprev = players[x].prevplayer;
            int thisnext = players[x].nextplayer;
            players[thisprev].nextplayer = thisnext;
            players[thisnext].prevplayer = thisprev;
        }else{
            if(players[x].prevplayer!=0){
                int thisprev = players[x].prevplayer;
                int thisnext = players[x].nextplayer;
                int prevprev = players[thisprev].prevplayer;
                players[x].prevplayer = prevprev;
                players[x].nextplayer = thisprev;
                players[thisprev].nextplayer = thisnext;
                players[thisprev].prevplayer = x;
                players[prevprev].nextplayer = x;
                players[thisnext].prevplayer = thisprev;
            }
        }
        int start = players[0].nextplayer;
        
        // while(start!=0){
        //     cout<<start<<' ';
        //     start = players[start].nextplayer;
        // }cout<<endl;
    }
    int people = 0;

    int start = players[0].nextplayer;
    vector<int> ans;
    while(start!=0){
        people++;
        ans.push_back(start);
        start = players[start].nextplayer;
    }
    
    cout<<ans[0];
    for(int i = 1; i<ans.size(); i++){
        cout<<' '<<ans[i];
    }cout<<endl;
    
    // //ranking[rank] = player
    // vector<int> ranking(n+1);
    // //players[player] = rank
    // vector<int> players(n+1);
    // for(int i = 1; i<=n; i++){
    //     ranking[i] = i;
    //     players[i] = i;
    // }
    // int end = ranking.size()-1;
    // for(int mm = 0; mm<m; mm++){
    //     int t, x; cin>>t>>x;
    //     if(t==0){
            
    //         for(int i = players[x]; i<ranking.size()-1; i++){
    //             ranking[i] = ranking[i+1];
    //             players[ranking[i]] = i;
    //         }
    //         ranking[end] = -1;
    //         end--;
    //         players[x] = -1;

    //     }else{
    //         if(players[x]==1){

    //         }else{
    //             int swapplayer = ranking[players[x]-1];
    //             swap(ranking[players[x]], ranking[players[swapplayer]]);
    //             swap(players[x], players[swapplayer]);
    //         }
    //     }
    // }

    
    // cout<<end<<endl;
    // for(int i = 1; i<=end; i++){
    //     cout<<ranking[i]<<' ';
    // }cout<<endl;
    // return 0;
}