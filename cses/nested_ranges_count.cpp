#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
struct range{
    int l; int r;
    int index;
    int sorted_index;
    //since indexing the bit with r wastes too much space, we index our ranges' end according to its position if sorted.
    //
};

// int debugger;

signed main(){
    // debugger = 0;
    // freopen("C:\\Users\\user\\Downloads\\test_input (3).txt", "r", stdin);
    int n; cin>>n;
    
    vector<range> ranges(n);
    for(int i = 0; i<n; i++){
        cin>>ranges[i].l>>ranges[i].r;
        
        ranges[i].index = i;
    }
    
    auto rangecomp = [](range a, range b){
        if(a.l==b.l) return a.r>b.r;
        else return a.l<b.l;
    };
    auto rangecomp2 = [](range a, range b){
        //if the ends are the same, we want the range with smaller length be indexed smaller.
        if(a.r==b.r) return a.l>b.l;
        else return a.r<b.r;
    };
    sort(ranges.begin(), ranges.end(), rangecomp2);
    for(int i = 0; i<n; i++){
        ranges[i].sorted_index = i+1;
    }
    sort(ranges.begin(), ranges.end(), rangecomp);

    
    vector<int> bit(n+2, 0);
    auto lsb = [](int n){
        return n & -n;
    };
    auto query = [&](int index){
        int ans = 0;
        while(index>0){
            ans+=bit[index];
            index-=lsb(index);
        }
        return ans;
    };
    auto update = [&](int index, int change){
        while(index<bit.size()){
            bit[index]+=change;
            index+=lsb(index);
        }
        
    };
    //bitend
    vector<int> ans1(n);
    for(int i = n-1; i>=0; i--){
        // int wqertty = ranges[i].sorted_index;
        // cout<<ranges[i].l<<' '<<ranges[i].r<<endl;
        // for(int j = 1; j<=n; j++){
        //     cout<<query(j)<<' ';
        // }cout<<endl;
        // cout<<query(ranges[i].sorted_index)<<endl;
        int b = query(ranges[i].sorted_index);
        // cout<<"b: "<<b<<endl; 
        //if b>0, there must be a range before this range that ends before (or on) this range's end
        // cout<<ranges[i].l<<' '<<ranges[i].r<<endl;
        ans1[ranges[i].index] = b;
        // cout<<"ans1[ranges[i].index]: "<<ans1[ranges[i].index]<<endl;
        update(ranges[i].sorted_index, 1);
    }
    for(int i = 0; i<n; i++){
        cout<<ans1[i]<<' ';
    }
    cout<<endl;
    for(auto &qwer: bit){
        qwer = 0;
    }
    for(int i = 0; i<n; i++){
        //if b>0, there is change at sorted index, there must be a range with a end later than (or containing) this range's end
        int b = query(n)-query(ranges[i].sorted_index-1);
        ans1[ranges[i].index] = b;
        update(ranges[i].sorted_index, 1);
    }
    for(int i = 0; i<n; i++){
        cout<<ans1[i]<<' ';
    }
    cout<<endl;
    
    
    
    // for(int i = 0; i<n-1; i++){
    //     for(int j = i+1; j<n; j++){
    //         if(ranges[i].l<=ranges[j].l&&ranges[i].r>=ranges[j].r){
    //             ranges[i].child.push_back(j);
    //             ranges[j].parent.push_back(i);
    //         }
    //         if(ranges[i].l>=ranges[j].l&&ranges[i].r<=ranges[j].r){
    //             ranges[j].child.push_back(i);
    //             ranges[i].parent.push_back(j);
    //         }
    //     }
    // }
    // for(int i = 0; i<n; i++){
    //     if(ranges[i].child.size()!=0){
    //         cout<<1<<' ';
    //     }else{
    //         cout<<0<<' ';
    //     }
    // }
    // cout<<endl;
    // for(int i = 0; i<n; i++){
    //     if(ranges[i].parent.size()!=0){
    //         cout<<1<<' ';
    //     }else{
    //         cout<<0<<' ';
    //     }
    // }

}