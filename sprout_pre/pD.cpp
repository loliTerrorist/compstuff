#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin>>n>>q;
    vector<vector<int> >  paper(n,vector<int>(n,0));
    for(int qq = 0; qq<q; qq++){
        int op, i, k; cin>>op>>i>>k;
        if(op==1){
            i = n-i;
            //x-y=i -> x=y+i
            for(int j = 0; j+i<n; j++){
                int y = j; int x = j+i;
                y=j;
                if(x<n&&x>=0&&y<n&&y>=0){
                    if(paper[j][j+i]<k) paper[j][j+i]=k;
                }
            }
        }else if(op==2){
            //x+y=i
        i--;
            for(int j = 0; j<=i;j++){
                int y = j; int x = i-j;
                y=j;
                if(j<n&&i-j<n){
                    if(paper[j][i-j]<k){
                        paper[j][i-j]=k;
                    }
                }
            }
        }
    }
    for(auto vv: paper){
        for(auto vvv:vv){
            cout<<vvv<<" ";
        }
        cout<<endl;
    }
}