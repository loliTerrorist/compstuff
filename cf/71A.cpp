#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    

    for(int i =0 ;i<n;i++){
        string in; cin>>in;
        if(in.size()>10){
            cout<<in[0]<<(in.size()-2-1+1)<<in[in.size()-1]<<endl;
        }else{
            cout<<in<<endl;
        }

    }
}