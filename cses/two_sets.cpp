#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main(){
    int n; cin>>n;
    if(n%4==1||n%4==2){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        if(n%4==3){
            cout<<((n-3)/4+1)*2<<endl;
            for(int i = 1; 4*i-1<=n; i++){
                cout<<4*i-3<<' '<<4*i-2<<' ';
            }
            cout<<endl;
            
            cout<<((n-3)/4+1)*2-1<<endl;
            for(int i = 1; 4*i-1<=n; i++){
                if(i==1){
                    cout<<4*i-1<<' ';
                }else{
                    cout<<4*i-4<<' '<<4*i-1<<' ';
                }
            }
            cout<<endl;
        }

        if(n%4==0){
            int k = n/4;
            cout<<2*k<<endl;
            for(int i = 1; i<=k; i++){
                if(i==1){
                    cout<<4*i-3<<' ';
                }else{
                    cout<<4*i-4<<' '<<4*i-3<<' ';
                }
            }
            cout<<4*k<<endl;
            

            cout<<2*k<<endl;
            for(int i = 1; i<=k; i++){
                cout<<4*i-2<<' '<<4*i-1<<' ';
            }
            cout<<endl;
        }
        
    }
}
