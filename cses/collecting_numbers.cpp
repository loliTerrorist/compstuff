#include <bits/stdc++.h>
#define int long long
#define endl '\n'



using namespace std;

signed main(){
    cin.tie(0);
    int n; cin>>n;
    vector<int> x(n); for(int i = 0; i<n; i++) cin>>x[i];
    vector<int> group(n+1, -1);
    int tag = 0;
    for(int i = 0; i<n; i++){
        if(group[x[i]]==-1){
            if(group[x[i]-1]==-1){
                group[x[i]]=tag; tag++;
            }else{
                group[x[i]]=group[x[i]-1];
            }
        }
    }
    cout<<tag<<endl;
    
    // vector<bool> ok(n+1,0);
    // int round = 0;
    // while(ok[n]==0){
    //     for(int i = 0;i<n; i++ ){
    //         if(ok[now]) continue;
    //         if(x[i]==now){
    //             ok[now]=1;
    //             now++;
    //         }
    //     }
    //     round++;
    // }
    // cout<<round<<endl;
}