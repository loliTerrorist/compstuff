#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int> 
#define endl "\n"

using namespace std;

int main(){
    string s; cin>>s;
    int n; cin>>n;
    while(n--){
        string t; cin>>t;
        int maxscore = -1;
        for(int i = 1; i<=min(s.size(), t.size()); i++){
            if(s.substr(s.size()-i, i)==t.substr(0,i)){
                maxscore = max(min(i, (int)t.size()-i),maxscore);
            }
        }
        cout<<maxscore<<endl;
    }
}



