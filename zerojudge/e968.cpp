#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[3];
    for(int i = 0; i<3; i++){
        cin>>a[i];
    }
    for(int i = n; i>0; i--){
        bool y = 1;
        for(int x: a){
            if(i==x) y=0;
        }
        if(y){
            cout<<"No. "<<i<<endl;
        }
    }
}