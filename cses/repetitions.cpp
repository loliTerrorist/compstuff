#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    // char c[4] = {'A', 'C', 'G', 'T'};
    string s; cin>>s;
    int ans = 1;
    int max=1;
    char temp;
    for(int i = 0; i<s.length(); i++){
        if(i>0){
            if(temp==s[i]){
                ans++;
            }else{
                if(ans>max) max=ans;
                ans=1;
            }
            if(ans>max) max=ans;
        }
        temp = s[i];
    }
    cout<<max<<endl;
}