#include <bits/stdc++.h>

using namespace std;
struct sip{
    string s;
    int c;
};
int main(){
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    for(int i = 1; i<=t; i++){
        vector<sip> v(10);
        int maxr = 1;
        for(int j = 0; j<10; j++){
            cin>>v[j].s>>v[j].c;
            if(v[j].c>maxr) maxr = v[j].c;
        }
        cout<<"Case "<<"#"<<i<<":"<<endl;
        for(int j = 0; j<10;j++){
            if(v[j].c==maxr){
                cout<<v[j].s<<endl;
            }
        }

    }

}