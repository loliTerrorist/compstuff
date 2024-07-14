#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
signed main(){
    bool a, b, ob;
    int ina, inb;
    cin>>ina>>inb>>ob;
    if(ina>0) a = 1;
    else a = 0;
    if(inb>0) b = 1;
    else b = 0;
    
    int counter = 0;
    if((a&&b)==ob){
        cout<<"AND"<<endl;
        counter++;
    }
    if((a||b)==ob){
        cout<<"OR"<<endl;
        counter++;
    }
    if((a^b)==ob){
        cout<<"XOR"<<endl;
        counter++;
    }
    if(counter==0){
        cout<<"IMPOSSIBLE"<<endl;
    }

}