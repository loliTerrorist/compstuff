#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n,m; cin>>n>>m;
    int h,t; multiset<int> tickets;

    for(int i = 0; i<n; i++){
        cin>>h; tickets.insert(h);
    }
    for(int i = 0; i<m; i++){
        cin>>t; 
        auto price = tickets.upper_bound(t);
        if(price==tickets.begin()){
            cout<<-1<<endl;
        }else{
            price--;
            cout<<*(price)<<endl;
            tickets.erase(price);
        }
        
    }
    
    
    
}