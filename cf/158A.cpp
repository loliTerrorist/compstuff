#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int ans = 0;
    int counter=0;
    int prev = 0;
    for(int i = 0; i<n; i++){
        int temp; cin>>temp;
        if(temp>0){
            counter++;
            if(counter<=k){
                ans++;
            }else{
                if(temp==prev){
                    ans++;
                }else{
                    break;
                }
            }
            prev = temp;

        }else{
            break;
        }
    }
    cout<<ans<<endl;
}