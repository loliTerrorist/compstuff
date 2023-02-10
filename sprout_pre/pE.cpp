#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int minn = 1e9; int maxx = -1e9;
    vector<vector<int> > vec(n, vector<int>(2));
    ll dif = 0;    
    for(int i =0; i<n;i++){
        cin>>vec[i][0];
        minn = min(vec[i][0],minn); maxx=max(vec[i][0],maxx);
        vec[i][1] = k-vec[i][0];
    }
    dif = maxx-minn;
    vector<bool> state(n,0);

    for(int i = 0; i<n;i++){
        int nmax = -1e9; int nmin = 1e9;
        int ndif = 0;
        state[i] = 1;
        for(int j = 0; j<n;j++){
            nmax = max(nmax, vec[j][state[j]]);
            nmin = min(nmin, vec[j][state[j]]);   
        }
        ndif = nmax-nmin;
        if(ndif<dif){
            dif = ndif;
            
        }else if(ndif>dif){
            state[i]=0;
        }
    }
    
    cout<<dif<<endl; 


    
}