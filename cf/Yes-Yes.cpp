#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
using namespace std;
string y = "Yes";
bool check(string instr){
    int offset;
    bool ans = 1;
    char fc = instr[0];
    if(fc=='Y'){
        offset=0;
    }else if(fc=='e'){
        offset=1;
    }else if(fc=='s'){
        offset=2;
    }else{
        return 0;
    }
    for(int i = 0; i<instr.size(); i++){
        if(instr[i]!=y[(i+offset)%3]){
            ans=0;
            return 0;
        }
    }
    return ans;
}
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        string instr; cin>>instr;
        if(check(instr)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}