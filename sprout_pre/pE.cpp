#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int minn = 1e9; int maxx = 0;
    for(int i =0; i<n;i++){
        int temp; cin>>temp;
        minn = min(abs(temp), minn);
        maxx = max(abs(temp), maxx);
    }
    cout<<maxx-minn<<endl;
}