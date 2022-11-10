#include <bits/stdc++.h>
using namespace std;
#define long long int

int main(){
    int a, b;
    while(cin>>a>>b){
        int count = 0;
            if(a == 1) a++;
            
            for(int i = a; i<=b; i++){
                
                bool yes = 1;
                for(int j = 2; j<=sqrt(i); j++){
                    if(i%j==0){
                        yes=0;
                        
                        break;
                    }
                }
                if(yes) count++;
            }
            cout<<count<<endl;
            
    }
   
}
