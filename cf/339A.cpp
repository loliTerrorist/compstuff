#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;

int main(){
    string in; cin>>in;
    vector<int> v;
    for(auto c: in){
        if(c!='+'){
            v.pb(c-'0');
        }
    }
    sort(v.begin(), v.end());
    if(v.size()==1) {
        cout<<v[0]<<endl;
    }else{
        cout<<v[0];
        for(int i = 1; i<v.size(); i++){
            cout<<'+'<<v[i];
        }
    }
}