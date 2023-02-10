#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    
    int n, t; cin>>n>>t;
    string s; cin>>s;
    for(int i = 1; i<=t; i++){
        string news = s;
        for(int j = 0; j<n-1; j++){
            if(s[j]=='B'&&s[j+1]=='G') swap(news[j],news[j+1]);
        }
        s = news;
    }
    cout<<s<<endl;
}