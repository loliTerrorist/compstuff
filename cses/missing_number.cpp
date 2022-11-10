#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin>>n;
    ll sumno = 0;
    ll temp;
    for(int i = 0; i<n-1; i++){
        cin>>temp;
        sumno+=temp;

    }
    cout<<(1+n)*n/2-sumno<<endl;
}