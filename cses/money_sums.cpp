#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> xs(n);
    int maxsum = 0;
    for(int i = 0; i<n; i++){
        cin>>xs[i];
        maxsum += xs[i];
    }
    sort(xs.begin(), xs.end());
    vector<vector<bool> > possible(n, vector<bool>(maxsum+1, 0));
    set<int> possibleset;
    //possible[a][b]: using xs[:a], is it possible to make sum b
    possible[0][xs[0]] = 1;
    possibleset.insert(0);

    for(int i = 0; i<n; i++){
        set<int> temppos = possibleset;
        for(auto val: temppos){
            possible[i][xs[i]+val] = 1;
            possibleset.insert(xs[i]+val);
        }
    }

    cout<<possibleset.size()-1<<endl;
    for(auto a: possibleset){
        if(a!=0) cout<<a<<' ';
    }
    cout<<endl;


    
}