#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1, m1, h2, m2;
    cin.tie(0);
    while(1){
        int ans = 0;
        
        cin>>h1>>m1>>h2>>m2;
        if(h2>h1){
            ans+=60*(h2-h1)+m2-m1;
        }else if(h2==h1){
            if(m2>=m1){
                ans+=m2-m1;
            }else{
                ans+=60*(24+h2-h1)+m2-m1;
            }
        }else{
            ans+=60*(24+h2-h1)+m2-m1;
        }
        if(h1+h2+m1+m2==0){
            break;
        }
        
            cout<<ans<<endl;
        
    }
}
