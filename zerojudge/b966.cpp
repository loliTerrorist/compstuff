#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;

int main(){
    vector<int> line(10000000,0);
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int l, r; cin>>l>>r;
        for(int j=l; j<r; j++){
            line[j]++;
        }
    }
    int ans = 0;
    for(auto i:line){
        if(i!=0){
            ans++;
        }
    }
    cout<<ans<<endl;
}