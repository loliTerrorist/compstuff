#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

/*
let our order of action be a1 d1, a2 d2....
the total reward is 
    (d1 - a1) + (d2-(a1+a2)) + (d3 - (a1+a2+a3))...
 =  (d1+d2+...dn) - (n*a1+(n-1)*a2+...)

therefore, we want a_k < a_(k+1)
*/
// bool comp(pair<int,int> a, pair<int,int> b){
//     if(a.first>b.first) return false;
//     else return true;
// }
signed main(){
    int n; cin>>n;
    vector<pair<int,int> > tasks(n, pair<int,int>());
    for(int i = 0; i<n; i++){
        cin>>tasks[i].first>>tasks[i].second;
    }
    // function<bool(pair<int,int>, pair<int,int>)> comp = [&](pair<int,int> a, pair<int, int>b){
      
    //     if(a.first>b.first) return false;
    //     else return true;
        
    // };
    sort(tasks.begin(), tasks.end());
    int currtime = 0;
    int reward = 0;
    for(int i = 0; i<n; i++){
        currtime+=tasks[i].first;
        reward += tasks[i].second - currtime;
    }
    cout<<reward<<endl;
}