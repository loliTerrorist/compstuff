#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int y = 0;
    auto check = [&](int &y, char c) mutable{
        switch(y){
            case 0:
                if(c=='h'){
                    y++; 
                }
                break;
            case 1:
                if(c=='e'){
                    y++;
                }
                break;
            case 2:
                if(c=='l'){
                    y++;
                }
                break;
            case 3:
                if(c=='l'){
                    y++;
                }
                break;
            case 4:
                if(c=='o'){
                    y++;
                }
                break;
        }
    };
    for(auto c:s){
        check(y,c);
    }
    if(y==5){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}