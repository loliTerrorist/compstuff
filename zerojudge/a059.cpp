#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){

        int a, b; cin>>a>>b;
        int s=0;
                 
        int start = ((int)sqrt(a)<sqrt(a))? (int)sqrt(a)+1: (int)sqrt(a);
        
        
        for(int i = start; i<=(int)sqrt(b); i++){
            
            s+=i*i;
        }
    
        cout<<"Case "<<i+1<<": "<<s<<endl;
    }
}
// 9+16+25