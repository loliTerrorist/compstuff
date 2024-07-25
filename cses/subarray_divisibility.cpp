#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void printmap(map<int, int> m){
    for(auto &p: m){
        cout<<"{"<<p.first<<": "<<p.second<<"} ";
    }
    cout<<endl;
}
signed main(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    vector<int> pre_sum(n+1); //this is pre_sum%n
    map<int, int> num_o_sum;
    num_o_sum[0]+=1; 
    int count = 0;
    for(int i = 1; i<=n; i++){
        pre_sum[i] = (pre_sum[i-1] + a[i])%n;
        pre_sum[i] += (pre_sum[i]<0)*n; // make it positive, smh wtf cpp
        count += num_o_sum[pre_sum[i]];
        num_o_sum[pre_sum[i]]++;
        // printmap(num_o_sum);
    }
    cout<<count<<endl;
}