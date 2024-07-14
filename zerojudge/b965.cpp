#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
vector<vector<int> > rotate(vector<vector<int> > original){
    vector<vector<int> > ret(original[0].size(), vector<int>(original.size()));
    for(int i = 0; i<original[0].size(); i++){
        for(int j = 0; j<original.size();j++){
            ret[i][j] = original[j][original[0].size()-1-i];
        }
    }
    return ret;
}
vector<vector<int> > flip(vector<vector<int> > original){
    vector<vector<int> > ret(original.size(), vector<int>(original[0].size()));
    for(int i = 0; i<original.size(); i++){
        for(int j = 0; j<original[0].size(); j++){
            ret[i][j] = original[original.size()-1-i][j];
        }
    }
    return ret;
}
signed main(){
    // cout.tie(0);
    int r;
    while(cin>>r){
        int c, m; cin>>c>>m;
        // cout<<'r'<<r<<endl;
        vector<vector<int> > b(r, vector<int>(c));
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                cin>>b[i][j];
            }
        }
        vector<int> moves(m);
        for(int i = 0; i<m; i++){
            cin>>moves[i];
        }
        vector<vector<int> > a = b;
        for(int i = m-1; i>=0; i--){
            if(moves[i]==0){
                a = rotate(a);
            }else{
                a = flip(a);
            }
            // cout<<"ansstart"<<endl;
            
            // cout<<"ansend"<<endl;
        }
        cout<<a.size()<<' '<<a[0].size()<<endl;
        for(int i = 0; i<a.size(); i++){
            cout<<a[i][0];
            for(int j = 1; j<a[0].size(); j++){
                cout<<' '<<a[i][j];
            }
            cout<<endl;
        }
    }
    
    

}