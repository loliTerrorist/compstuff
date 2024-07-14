#include <bits/stdc++.h>

using namespace std;

signed main(){
    int n; cin>>n;
    cout.tie(0);
    vector<int> frog_pos(n+1);
    vector<int> lilies(n+1e6, 0);
    for(int i = 1; i<=n; i++){
        cin>>frog_pos[i];
        lilies[frog_pos[i]] = 1;
    }
    
    int q; cin>>q;
    auto jump = [&](int index){
        int oldpos = frog_pos[index];
        int i = oldpos+1;
        for(; lilies[i]!=0; i++){
        }
        frog_pos[index] = i;
        lilies[i] = 1;
        lilies[oldpos] = 0;
        cout<<i<<endl;
    };
    for(int i = 0; i<q; i++){
        int temp; cin>>temp;
        jump(temp);
    }
}