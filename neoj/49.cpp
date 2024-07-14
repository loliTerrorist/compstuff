#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
struct node{
    vector<int> childs;
    int val;
};
// int ccount(node &nd){
//     int returnval = 0;
//     for(auto child: nd.childs){
//         returnval += ccount(child);
//     }
//     returnval++;
//     return returnval;
// }
// vector<node> nodes;
// int ccount(int ndindex);
signed main(){
    cin.tie(0);cout.tie(0);
    int t; cin>>t;
    int n, m; cin>>n>>m;
    vector<node> nodes(n+1);
    // for(int i = 0; i<n; i++){
    //     nodes[0].childs.push_back(i);
    // }
    set<int> starting;
    for(int i = 1; i<=n; i++){
        starting.insert(i);
    }
    function<int(int)> ccount = [&](int ndindex){
        int returnval = 0;
        for(auto childindex: nodes[ndindex].childs){
            returnval += ccount(childindex);
        }
        returnval++;
        nodes[ndindex].val = returnval;
        return returnval;
    };
    
    // for(int i = 1; i<=n; i++){
    //     nodes[i].val = i;
    // }
    for(int i = 0; i<m; i++){
        int x, y; cin>>x>>y;
        nodes[x].childs.push_back(y);
        starting.erase(starting.find(y));
    }
    int q; cin>>q;
    // cout<<endl;
    for(auto i: starting){
        ccount(i);
    }
    
    while(q--){
        int x; cin>>x;
        cout<<nodes[x].val<<endl;
    }
}

// int ccount(int ndindex){
//     int returnval = 0;
//         for(auto childindex: nodes[ndindex].childs){
//             returnval += ccount(childindex);
//         }
//         returnval++;
//         return returnval;
// }