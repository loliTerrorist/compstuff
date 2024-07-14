#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;



signed main(){
    int n; cin>>n;
    int k; cin>>k;
    vector<int> bit(n+1,0);
    auto lsb = [&](int i){
        return (i&-i);
    };
    auto query = [&](int i){
        int sum = 0;
        while(i>0){
            sum+=bit[i];
            i-= lsb(i);
        }
        return sum;
    };
    auto change = [&](int i, int d){
        while(i<=n){
            bit[i]+=d;
            i+=lsb(i);
        }
    };
    for(int i = 1; i<=n; i++){
        change(i,1);
    }
    int index = 1;
    int size = n;
    auto search = [&](int i){
        int power = 1;
        for(; power<n; power*=2){};
        
        int sum = 0;
        for(; power>=1; power/=2){
            int temp = query(sum+power);
            if(sum+power<=n&&query(sum+power)<index){
                sum+=power;
            }
        }
        sum++;
        return sum;
    };
    for(int i = 0; i<n; i++){
        index = (index-1+k)%size+1;
        // for(int j = 1; j<=n; j++){
        //     cout<<query(j)<<' ';
        // }cout<<endl;
        cout<<search(index)<<endl;
        change(search(index), -1);
        size--;
    }
}