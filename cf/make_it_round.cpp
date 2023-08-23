#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int long long
#define pb push_back
using namespace std;
int maxpwrof(int a,int b){
    int ans = 0;
    int temp = 1;
    while(temp<=a){
        ans++;
        temp*=b;
    }
    ans--;
    return ans;
}
//logn
int trailingzeros(int a){
    int ans = 0;
    int temp = 1;
    for(;a%(temp)==0;temp*=10){
        ans++;
    }
    ans--;
    return ans;
}
//n
int pwrof(int a, int b){
    int ans = 0;
    int temp = 1;
    for(;a%temp==0;temp*=b){
        ans++;
    }
    ans--;
    return ans;
}
signed main(){
    // cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        int maxadd5 = maxpwrof(m,5);
        int maxadd2 = maxpwrof(m,2);
        int maxadd10 = min(maxadd5, maxadd2);
        int nof2 = pwrof(n,2);
        int nof5 = pwrof(n,5);
        int nof10 = min(nof2,nof5);
        int k = 1;
        while(k<=m&&((maxadd2>0||maxadd5>0)||maxadd10>0)){
            if(nof2<nof5&&maxadd2>0&&k*2<=m){
                nof2++;
                maxadd2--;
                k*=2;
            }else
            if(nof5<nof2&&maxadd5>0&&k*5<=m){
                nof5++;
                k*=5;
                maxadd5--;
            }else{
                
                nof10 = min(nof2,nof5);
                maxadd10 = min(maxadd5,maxadd2);
                if(maxadd10>0&&k*10<=m){
                    maxadd10--;
                    maxadd2--;
                    maxadd5--;

                    k*=10;
                    nof10++;
                }else{
                    for(int i = 9; i>1; i--){
                        if(k*i<=m){
                            k*=i;
                        }
                    }
                    break;

                // else if(maxadd5>0&&k*5<=m){
                //     k*=5;
                //     nof5++;
                //     maxadd5--;
                // }
                // else if(maxadd2>0&&k*2<=m){
                //     k*=2;
                //     maxadd2--;
                //     nof2++;
                // }else{
                //     k*=(m/k);
                //     break;
                // }
                
                
            }
        }
        
        // cout<<"ans: ";
        if(trailingzeros(n*k)!=0) cout<<n*k<<endl;
        else cout<<n*m<<endl;
        // cout<<"k: "<<k<<endl;
        
    }

}