#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;
void printvec(vector<string> vec){
    for(auto s: vec){
        cout<<s<<endl;
    }
}
int main(){
    int n, q; cin>>n>>q;
    vector<string> texts(n);
    string dump;
    getline(cin,dump);

    for(int i = 0; i<n; i++){
        // cout<<"i: "<<i<<endl; 
        getline(cin, texts[i]);
        // cout<<"texts: " <<texts[i]<<endl;
    }
    string clip;
    for(int i = 0; i<q; i++){
        string op; cin>>op;
        if(op=="cut"){
            int i, l, r;
            cin>>i>>l>>r;
            clip = texts[i].substr(l,r-l+1);
            // cout<<"clip: "<< clip<<endl;
            // if(l==0) l=1;
            // if(r==texts[i].size()-1) r = texts[i].size()-2;
            // cout<<"pre: "<<texts[i].substr(0,l)<<"endl"<<endl;
            if(r!=texts[i].size()){
                texts[i] = texts[i].substr(0,l)+texts[i].substr(r+1,texts[i].size()-r-1);
            }else{
                texts[i] = texts[i].substr(0,l);
            }
            // printvec(texts);
        }else if(op=="paste"){
            int i, p; cin>>i>>p;
            
            // cout<<"pre: "<<texts[i].substr(0,p+1)<<endl;
            // cout<<"suf: "<<texts[i].substr(p,texts[i].size()-p-1)<<endl;
            // cout<<"clip: "<<clip<<endl;
            if(p == 0){
                texts[i] = clip+texts[i];
            }else if(p==texts[i].size()){
                texts[i] += clip;
            }else{
                texts[i] = texts[i].substr(0,p)+clip+texts[i].substr(p,texts[i].size()-p);
            }
            // printvec(texts);
        }
    }
    for(int i =0; i<n; i++){
        cout<<texts[i]<<endl;
    }
    
}