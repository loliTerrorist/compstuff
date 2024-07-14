#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    vector<int> a(3);
    for(int i = 0; i<3; i++){
        cin>>a[i];

    }
    sort(a.begin(), a.end());
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    if(a[0]+a[1]<=a[2]){
        cout<<"No"<<endl;
    }
    else{
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]){
            cout<<"Right"<<endl;
        }
        if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2]){
            cout<<"Acute"<<endl;
        }
        if(a[0]*a[0]+a[1]*a[1]<a[2]*a[2]){
            cout<<"Obtuse"<<endl;
        }
    }
}