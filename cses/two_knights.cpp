#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll check(ll k){
    ll total = k*k*(k*k-1)/2;
    ll m = 2*(k-3+1)*(k-2+1);
    return total - 2*m;
    
}
int main(){
    ll n; cin>>n;
    for(ll i = 1; i<=n; i++){
        cout<<check(i)<<endl;
    }
}