#include <bits/stdc++.h>

using namespace  std;

int main(){
    int n, m, a;
    cin>>n>>m>>a;
    long long an, am;
    if(n%a==0){
        an=n/a;
    }else{
        an=n/a+1;
    }
    if(m%a==0){
        am=m/a;
    }else{
        am=m/a+1;
    }
    cout<<an*am<<endl;
}