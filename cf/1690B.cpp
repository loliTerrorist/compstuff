#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        bool ans = 1;
        int last = -1;
        // int maxdif = -1;
        vector<int> a(n); vector<int> b(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        for(int i = 0; i<n; i++){
            cin>>b[i];
            if(a[i]<b[i]){
                ans = 0; 
                
            }
            
            if(b[i]>0){
                
                if(last!=-1&&(a[i]-b[i])!=last){
                    ans = 0;  
                }
                last = a[i]-b[i];
            }

        }
        for(int i = 0; i<n; i++){
            if(b[i]==0){
                if(a[i]-b[i] > last&&last!=-1){
                    ans = 0;
                }
            }
        }
        
        if(ans==0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }     
    }
}