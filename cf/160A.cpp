#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    sort(v.begin(), v.end());
    int my = 0;
    int coins = 0;
    for(int i = 0; i<n;i++){
        my+=v[n-1-i];
        coins++;
        sum-=v[n-1-i];
        if(my>sum) break;
    }
    cout<<coins<<endl;
}