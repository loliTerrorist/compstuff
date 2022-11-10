#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int year; cin>>year;
        bool ans;
        if(year%4==0){
            if(year%400!=0 && year%100==0){
                ans=0;
            }else{
                ans=1;
            }
        }else{
            ans=0;
        }
        if(ans){cout<<"a leap year"<<endl;}else{cout<<"a normal year"<<endl;}
    }
}