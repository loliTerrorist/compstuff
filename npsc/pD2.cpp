#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int> 
#define endl "\n"

using namespace std;
struct node{
    int val = 0;
    int l, r;
    node* lchild; node* rchild;
};
void build(){
    
}
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n; cin>>n;
    vector<ll> v(1000001, 0);
    while(n--){
        int start, fin; cin>>start>>fin;
        for(int i = start; i<fin; i++){
            v[i]++;
        }
    }
    
    ll ans = 0;
    for(int i = 0; i<1000001; i++){
        ans+=v[i]*(v[i]-1)/2;
    }
    cout<<ans<<endl;
}



