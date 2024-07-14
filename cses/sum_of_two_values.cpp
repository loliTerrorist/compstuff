#include <bits/stdc++.h>

//1 2 5 7
//
using namespace std;
//(i, value)
bool comp(pair<int, int>a, pair<int, int> b){
    if(a.second<b.second) return true;
    else return false;
}
int main(){
    // freopen("C:\\Users\\user\\Downloads\\test_input (1).txt", "r", stdin);
    int n; cin>>n;
    int x; cin>>x;
    vector<pair<int,int> > a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i].second;
        a[i].first = i;
    }
    sort(a.begin(), a.end(),comp);
    int l = 0; int r = n-1;
    bool found = 0;
    while(l<r){
        if(x-a[l].second==a[r].second){
            found=1;
            break;
        }else if(x-a[l].second>a[r].second){
            l++;
        }else{
            r--;
        }
    }
    if(found){
        cout<<a[l].first+1<<" "<<a[r].first+1<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}