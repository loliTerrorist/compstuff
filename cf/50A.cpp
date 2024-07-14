#include  <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back
using namespace std;

int main(){
    int m, n; cin>>m>>n;
    int ans = max(m,n)/2*min(m,n);
    ans+=(max(m,n)%2)*(min(m,n)/2);
    cout<<ans<<endl;
}