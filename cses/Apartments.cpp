#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    int n, m, k; cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    // vector<bool> occupied(m,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans=0;
    int i = 0; int j = 0;
    // int i = (n-1)/2; int j=(m-1)/2;
    // for(;i<n;){
    for(;j<m&&i<n;){
        if(a[i]<b[j]-k){
            i++;
        }else if(a[i]>b[j]+k){
            j++;
        }else{
            
            i++;
            j++;
            ans++;
        }
    }
    // }
    // for(int i = 0; i<n; i++){
    //     for(int j = 0;j<m;j++){
    //         if(b[j]-k<=a[i]&&b[j]+k>=a[i]&&occupied[j]==0){
    //             occupied[j]=1;
    //             ans++;
    //             break;
    //         }
    //         if(b[j]-k>a[i]){

    //         }
    //     }
    // }
    cout<<ans<<endl;

}