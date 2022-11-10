#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<string> perms;
    sort(s.begin(), s.end());
    do{
        perms.pb(s);
    }while(next_permutation(s.begin(), s.end()));
    cout<<perms.size()<<endl;
    for(auto ss: perms){
        cout<<ss<<endl;
    }
}