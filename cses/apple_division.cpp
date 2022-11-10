#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> p(n);
    for(int i = 0; i<n; i++){
        cin>>p[i];
    }
    ll m = 1e18;
    for(int i = 0; i<(1<<n); i++){
        ll a = 0;
        ll b = 0;
        for(int j = 0; j<n; j++){
            if(i&(1<<j)) a+=p[j];
            else b+=p[j];
        }
        m = min(m, abs(a-b));

    }
    cout<<m<<endl;

}