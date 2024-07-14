#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool comp(pair<int, int> a, pair<int, int>  b){
    if(b.second>a.second){
        return true;
    }else if(b.second == a.second){
        if(a.first<b.first) return true;
        else return false;
    }else{
        return false;
    }
}
int main(){
    // freopen("C:\\Users\\user\\Downloads\\test_input.txt", "r", stdin);
    int n; cin>>n;
    cin.tie(0); //ios::sync_with_stdio(0); 
    vector<pair<int, int> > movies(n);
    for(int i = 0; i<n; i++){
        cin>>movies[i].first>>movies[i].second;
    }
    sort(movies.begin(), movies.end(), comp);
    int end = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(movies[i].first>=end){
            end = movies[i].second;
            ans++;
        }
    }
    cout<<ans<<endl;
    
}