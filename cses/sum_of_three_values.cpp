#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main(){
    int n, x; cin>>n>>x;
    vector<pair<int,int> > nums = vector<pair<int,int> >(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i].first;
        nums[i].second = i;
    }
    sort(nums.begin(), nums.end());
    int third;
    bool ansfound = 0;
    int left = 0; int right = n-1; 
    auto twopointer = [&](){  
        while(left<right){
        int goal = x-nums[third].first;
        int currsum = nums[left].first+nums[right].first;
            if(currsum==goal&&left!=third&&right!=third){
                ansfound=1;
                break;
            }else{
                if(currsum>goal) {right--;}
                else {left++;}
            }
        }
    };
    for(int i = 0; i<n; i++){
        third = i;
        left = 0; right = n-1;
        twopointer();
        if(ansfound) break;
    }
    
    if(ansfound){
        cout<<nums[left].second+1<<' '<<nums[third].second+1<<' '<<1+nums[right].second<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}