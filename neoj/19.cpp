#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        stack<int> a;
        for(int i = 1; i<=n; i++){
            a.push(i);
        }
        stack<int> b;
        vector<int> binput(n);
        for(int i = 0; i<n; i++){
            cin>>binput[i];
            b.push(binput[i]);
        }
        for(int i = n-1; i>=0; i--){

        }
        stack<int> middle;
        while(!b.empty()){
            while(!middle.empty()){
                if(middle.top()==a.top()){
                    middle.pop();
                    a.pop();
                }else{
                    break;
                }
            }
            
            middle.push(b.top());
            b.pop();
            
        }
        bool ans;
        if(middle.empty()){
            ans = 1;
        }else{
            while(!middle.empty()){
                if(a.top()!=middle.top()){
                    ans = 0; break;
                }else{
                    a.pop();
                    middle.pop();
                }
            }
            if(middle.empty()){
                ans = 1;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}