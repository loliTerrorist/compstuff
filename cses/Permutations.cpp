#include <bits/stdc++.h>
#define ll long long;
#define endl "\n"
using namespace std;
int main(){
    int n; cin>>n;
    if(n==2 or n==3){
        cout<<"NO SOLUTION"<<endl;
    }else if(n==1){
        cout<<1<<endl;
    }else if(n==4){
        cout<<"2 4 1 3"<<endl;
    }else{
        if(n%2){
            int m = n/2+1;
            for(int i = 1; i<m-1; i++){
                cout<<m+i<<' '<<m-i<<' ';
            }
            cout<<n<<' '<<m<<' '<<1<<endl;

        }
        else{
            int m = n/2;
            for(int i = 1; i<m-1; i++){
                cout<<m+i<<' '<<m-i<<' ';
            }
            cout<<n-1<<' '<<m<<' '<<1<<' '<<n<<endl;
        }
    }
}