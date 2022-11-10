#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
// #define int long long
using namespace std;
vector<vector<int> > hanoi(int n, int start, int end);


signed main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n; cin>>n;
    cout<<int(pow(2,n)-1)<<endl;

    for(vector<int> v: hanoi(n, 1, 3)){
        for(int vv: v){
            cout<<vv<<" ";
        }
        cout<<endl;
    }
}
int notin(int a, int b){
    return (6-a-b);
}
vector<vector<int> > hanoi(int n, int start, int end){
    vector<vector<int> > ans;
    if(n==1){
        ans = {{start, end}};
        
    }else{
        vector<vector<int> > fh = hanoi(n-1, start, notin(start,end));
        vector<vector<int> > sh = hanoi(n-1, notin(start, end), end);
        ans.insert(ans.end(), fh.begin(), fh.end());
        ans.push_back({start, end});
        ans.insert(ans.end(), sh.begin(), sh.end());
    }
    return ans;
}