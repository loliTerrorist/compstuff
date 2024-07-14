#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main(){
    int n; cin>>n;
    int x = 0; 
    for(int i = 0; i<n; i++){
        string in; cin>>in;;
        
        for(int j = 0; j<3; j++){
            if(in[j]=='+'){
                x++; break;
            }else if(in[j]=='-'){
                x--; break;
            }
        }
    }
    cout<<x<<endl;
}
