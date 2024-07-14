#include <bits/stdc++.h>

using namespace std;

int main(){
    int y; cin>>y;
    int q,w,e,r; 
    while(1){
        y++;q=y/1000; w=(y%1000)/100; e=(y%100)/10; r=(y%10);
        if(q!=w&&q!=e&&q!=r&&w!=e&&w!=r&&e!=r){
            break;
        }
    }
    cout<<y<<endl;

}