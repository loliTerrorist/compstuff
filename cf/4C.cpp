#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> acts;
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        string name; cin>>name;
        if(acts.find(name)==acts.end()){
            acts.insert(pair<string,int>(name,0));
            cout<<"OK"<<endl;
        }else{
            
            acts[name]++;
            cout<<name<<acts[name]<<endl;
        }
    }

}