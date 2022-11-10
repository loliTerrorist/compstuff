#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
    int n; cin>>n;
    vector<vector<int> > prev = {{0}, {1}};
    for(int i = 1; i<n; i++){
        vector<vector<int> > fh(prev.size()); 
        for(int j = 0; j<prev.size(); j++){
            fh[j] = prev[j];
            fh[j].pb(0);
        } 
        vector<vector<int> > sh(prev.size());
        int j = 0;
        for(vector<vector<int> >::reverse_iterator h = prev.rbegin(); h!=prev.rend(); h++){
            sh[j] = *h;
            sh[j].pb(1);
            j++;
        }
        prev = fh;
        prev.insert(prev.end(), sh.begin(), sh.end());
    }
    for(vector<int> v : prev){
        for(int vv: v){
            cout<<vv;
        }
        cout<<endl;
    }
    
}