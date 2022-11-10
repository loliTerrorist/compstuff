#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin>>n;
    int ans = 0;
    int currd = 5;
    while(currd<=n){
        ans+=n/currd;
        currd*=5;
    }
    cout<<ans<<endl;
}