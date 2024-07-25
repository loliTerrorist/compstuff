#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void printmap(map<int, int> m){
    for(auto &p: m){
        cout<<"{"<<p.first<<": "<<p.second<<"} ";
    }
    cout<<endl;
}
signed main(){
    int n, x;
    cin>>n>>x;
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    vector<int> prefix_sum(n+1, 0);
    map<int, int> available_sum;    
    available_sum[0]+=1; //[] is a subarray with sum 0
    
    


    int count = 0;

    for(int i = 1; i<=n; i++){
        prefix_sum[i] = prefix_sum[i-1]+a[i];
        //we want to find how many b exists where prefix_sum[i] - prefix_sum[b] = x
        int target = prefix_sum[i]-x;
        
        // cout<<"target: "<<target<<endl;
        count+=available_sum[target];
        // cout<<"count: "<<count<<endl;
        available_sum[prefix_sum[i]]+=1;
        // printmap(available_sum);
        // cout<<available_sum[prefix_sum[i]]<<endl;
    }

    cout<<count<<endl;
    

}