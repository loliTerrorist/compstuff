#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n%2){
            n=n*3+1;
        }else{
            n/=2;
        }
    }
    cout<<n<<endl;
}