#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
// int findv(int i, int j){
//     if(i==0) return 1;
//     if(j==0) return 1;
//     if(j<0) return 0;
//     return dp[i][j];
// }
void printvec(vector<map<int, int> > v){
    auto start = v[v.size()-1];
    cout<<"   ";
    for(auto m: start){
        cout<<m.first<<" ";
    }cout<<endl;
    for(int i = 0; i<v.size(); i++){
        cout<<i<<"  ";
        for(auto &p: v[i]){
            cout<<p.second<<" ";

        }
        cout<<endl;        
    }
}


signed main(){
    int n, x; cin>>n>>x;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int left = 0; int right = 0;
    int sum = 0;
    int count = 0;
    function<void()> rightmove = [&](){
        right++;
        sum+=a[right];
    };
    function<void()> leftmove = [&](){
        sum-=a[left];
        left++;
    };
    sum+=a[0];
    while(right<n){
        if(sum<x){
            rightmove();
        }else
        if(sum>x){
            leftmove();
        }else{
            count++;
            rightmove();
            leftmove();
        }
        int k = right; int kk = left; 
        int l = right;
    }
    while(left<n){
        if(sum==x){
            count++;
        }
        leftmove();
        int k = left; 
        int l = left;
    }

    cout<<count<<endl;



}

/*
4 7
1 1 2 3
*/