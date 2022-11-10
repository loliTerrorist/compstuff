#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n; cin>>n;
    // vector<int> v(n);
    ll moves = 0;
    int prev;
    for(int i = 0; i<n; i++){
        int curr; cin>>curr;
        if(i>0){
            while(curr<prev){
                curr++;
                moves++;
            }
        }
        prev = curr;
    }
    cout<<moves<<endl;
}