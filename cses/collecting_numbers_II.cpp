#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back


using namespace std;

signed main(){
    // freopen("C:\\Users\\user\\Downloads\\test_input (2).txt", "r", stdin);
    cin.tie(0);cout.tie(0);
    int n; cin>>n; int m; cin>>m;
    vector<int> x(n+2,0); for(int i = 1; i<=n; i++) cin>>x[i];
    vector<int> index(n+2);
    index[n+1] = 2e5;
    x[n+1] = n+1;
    for(int i = 0; i<n+2; i++){
        index[x[i]] = i;
    }
    // for(int i = 0; i<=n; i++){
    //     cout<<index[i]<<endl;
    // }
    
    int ans = 1;
    for(int i = 2; i<=n; i++){
        if(index[i]-index[i-1]<0){
            ans++;
        } 
    } // cout<<ans<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        // swap(x[a], x[b]);

        //if original index cause ans++, new index doesn't, ans--;
        int aval = x[a]; 
        int bval = x[b];
        vector<int> check = {aval, aval + 1, bval, bval + 1};
        int before, after; before = after = 0;
        sort(check.begin(), check.end());
        check.resize(unique(check.begin(), check.end()) - check.begin());
        // for(auto v: check){
        //     cout<<v<<" ";
        // }
        // cout<<endl;
        for(int i = 0; i<check.size(); i++){
            if(index[check[i]]<index[check[i]-1]) before++;
        }
        swap(index[x[a]],index[x[b]]);
        swap(x[a],x[b]);
        for(int i = 0; i<check.size(); i++){
            if(index[check[i]]<index[check[i]-1]) after++;
        }
        
        ans += after-before;
        cout<<ans<<endl;
    }

        // vector<int> group(n+1, -1);
        // int tag = 0;
        // for(int i = 0; i<n; i++){
        //     if(group[x[i]]==-1){
        //         if(group[x[i]-1]==-1){
        //             group[x[i]]=tag; tag++;
        //         }else{
        //             group[x[i]]=group[x[i]-1];
        //         }
        //     }
        // }
        // cout<<tag<<endl;
    
   
    
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