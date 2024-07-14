#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    // cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    vector<int> xs(n);
    for(int i = 0; i<n; i++){
        cin>>xs[i];
    }
    stack<pair<int, int> > smallervals;
    for(int i = 0; i<n; i++){
        while(!smallervals.empty()&&smallervals.top().first>=xs[i]){
            smallervals.pop();
        }
        if(smallervals.empty()){
            cout<<0<<' ';
        }else{
            cout<<smallervals.top().second+1<<' ';
        }
        pair<int, int> temppair = {xs[i], i};
        smallervals.push(temppair);
    }
    // vector<int> ds(n,0);
    // ds[0] = 0;
    // for(int i = 1; i<n; i++){
    //     for(int j = i-1; j>=0;){
    //         if(xs[j]<xs[i]){
    //             ds[i] = i-j;
    //             break;
    //         }else{
                
    //             if(ds[j]!=0) j = j-ds[j];
    //             else j--;
    //         }
    //     }
    // }
    // for(int i = 0; i<n; i++){
    //     if(ds[i]!=0) cout<<i-ds[i]+1<<' ';
    //     else cout<<0<<' ';
    //     // cout<<ds[i]<<' ';
    // }
    cout<<endl;
}