#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0; i<(1<<n); i++){
        string s;
        int val = i^(i>>1);
        bitset<32> b(val);
        s = b.to_string();
        cout<<s.substr(32-n)<<endl;
        // for(int j = 1; j<=n; j++){
        //     if(((i>>j)^i>>(j-1))%2){
        //         s+="1";
        //     }else{
        //         s+="0";
        //     }
        // }

        // for(string::reverse_iterator si = s.rbegin(); si!=s.rend(); si++){
        //     cout<<*si;
        // }
        // cout<<endl;
    }
}