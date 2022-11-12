#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
using namespace std;
int ans=0;
// if not available 1
vector<bool> sum(15,0), dif(15,0), c(8,0);
vector<string> vs(8);
void search(int r){
    if(r==8){
        ans++;
        return;
    }else{
        for(int i = 0; i<8;i++){
            if(vs[r][i]=='.'&&!sum[r+i]&&!dif[(r-i)+7]&&!c[i]){
                sum[r+i]=dif[7+(r-i)]=c[i]=1;
                search(r+1);
                sum[r+i]=dif[7+(r-i)]=c[i]=0;
            }
        }
    }
    
}

int main(){
    for(int i = 0; i<8;i++){
        cin>>vs[i];
    }
    search(0);
    cout<<ans<<endl;
}