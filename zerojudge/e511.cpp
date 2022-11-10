#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int max = 0;
        int min = 100;
        while(n--){
            int x; cin>>x;
            if(x>max) max=x;
            if(x<min) min=x;
        }
        cout<<(max-min)*2<<endl;
        

        
    }
}