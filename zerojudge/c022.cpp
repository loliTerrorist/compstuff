#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    int n = t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int ans = 0;
        for(int i = a; i<=b; i++){
            if(i%2==1) ans+=i;
        }
        cout<<"Case "<<n-t<<": "<<ans<<endl;
    }
}