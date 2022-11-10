#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int money = 0;
    while(n>=12){
        n-=12;
        money+=50;
    }
    while(n!=0){
        n--;
        money+=5;
    }
    cout<<money<<endl;
}