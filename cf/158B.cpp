#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> group(4,0);
    for(int i = 0; i<n; i++){
        int t; cin>>t;
        group[t-1]++;
    }
    int cars = 0;
    auto ne = [](vector<int> vec){
        for(auto c:vec){
            if(c!=0) return false; 
        }
        return true;
    };
    while(!ne(group)){
        if(group[3]>0){
            group[3]--;
            cars++;
        }else if(group[2]>0){
            if(group[0]>0){
                group[0]--;
            }
            group[2]--;
            cars++;
        }else if(group[1]>1){
            group[1]-=2;
            cars++;
        }else if(group[1]>0){
            group[1]--;
            if(group[0]>1){
                group[0]-=2;
            }else if(group[0]>0){
                group[0]--;
            }
            cars++;
        }else if(group[0]>4){
            group[0]-=4;
            cars++;
        }else if(group[0]>0){
            group[0] = 0;
            cars++;
        }
    }
    cout<<cars<<endl;
}