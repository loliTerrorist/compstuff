#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;

int main(){
    cin.tie(0);
    int x, y;

    for(int i = 0; i<5;i++){
        for(int j = 0; j<5;j++){
            int in; cin>>in;
            if(in){
                x=j;
                y=i;
                break;
            }
        }
    }
    cout<<abs(2-x)+abs(2-y)<<endl;
}