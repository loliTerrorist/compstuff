#include <bits/stdc++.h>
#define int long long
using namespace std;
bool issquare(int n){
    int start = sqrt(n);
    if(start*start!=n){
        return false;
    }else{
        return true;
    }
}
bool isint(double n){
    int a = n;
    if(a==n) return 1;
    else return 0;
}
signed main(){
    // double n; cin>>n;
    // cout<<isint(n)<<endl;
    int a, b;
    cin>>a>>b;
    int w = min(a, b);
    int h = max(a, b);
    w-=1; h-=1;
    int ans = 0;
    bool equ = 0;
    if(h!=w){
        ans+=2;
    }else{
        equ = 1;
        ans+=1;
    }
    for(int i = 1; i<w; i++){
        if(issquare(w*w-i*i)){
            
            
        
            // cout<<isint(h*(double)i/w)<<' '<<isint(h*sqrt(w*w-i*i)/w)<<endl;
            if(isint(h*(double)i/w)&&isint(h*sqrt(w*w-i*i)/w)){
                if(equ){
                    ans+=1;
                }else{
                    ans+=2;
                }
            }
        }
    }
    cout<<ans<<endl;
}