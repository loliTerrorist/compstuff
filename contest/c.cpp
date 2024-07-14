#include <bits/stdc++.h>

using namespace std;
void printvec(vector<bool> a){
    for(auto aa: a){
        cout<<aa<<' ';
    }
    cout<<endl;

}
signed main(){
    int n, q;
    cin>>n>>q;
    vector<bool> seg(n, 1);
    for(int i = 0;i < q; i++){
        char in; cin>>in;
        if(in=='+'){
            int a; cin>>a;
            a--;
            seg[a] = 1;
            
        }else if(in=='-'){
            int a; cin>>a;
            a--;
            seg[a] = 0;
        }else{
            // printvec(seg);
            int a, b; cin>>a>>b;
            a--; b--;
            bool ans1 = 1;
            bool ans2 = 1;
            if(seg[b]==0||seg[a]==0){
                ans1 = 0; ans2 = 0;
            }else{

                
                for(int i = a; i!=b; i = (i+1)%n){
                    // cout<<i<<' ';
                    if(seg[i]==0){
                        ans1 = 0;
                        break;
                    }
                }
                // cout<<endl;
                for(int i = a; i!=b; i = (i+n-1)%n){
                    // cout<<i<<' ';
                    if(seg[i]==0){
                        ans2 = 0;
                        break;
                    }
                }
            }
            // cout<<endl;
            if(ans1||ans2){
                cout<<"possible"<<endl;
            }else{
                cout<<"impossible"<<endl;
            }
        }
    }
}