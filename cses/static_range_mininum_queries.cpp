#include <bits/stdc++.h>
#define int long long
using namespace std;


struct node{
    int l, r;
    int lson, rson;
    int data;
};


signed main(){
    int n, q; cin>>n>>q;
    vector<int> arr(n);
    vector<node> st(2*n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int counter = 0;
    function<void(int, int, int)> build = [&](int l, int r, int index){
        st[index].l = l; st[index].r = r;
        if(l==r-1) st[index].data = arr[l];
        else{
            
            st[index].lson = 0;
            counter++;
            int lson = st[index].lson=counter;
            counter++;
            int rson = st[index].rson = counter;
            build(l, (l+r)/2, lson);
            build((l+r)/2, r, rson);
            st[index].data = min(st[lson].data, st[rson].data);
        }
    };
    function<int(int, int, int)> query = [&](int l, int r, int index){
        int mid = (st[index].l+st[index].r)/2;
        int lson = st[index].lson;
        int rson = st[index].rson;
        
        if(st[index].l==l&&st[index].r==r){
            return st[index].data;
        }
        else if(r<=mid){
            return query(l, r, lson);
        }
        else if(l>=mid){
            return query(l, r, rson);
        }else{
            return min(query(l,mid,lson), query(mid,r,rson));
        }
    };
    build(0, n, 0);
    // for(int i = 0; i<counter; i++){
    //     node n = st[i];
    //     cout<<i<<": "<<endl;
    //     cout<<"l: "<<n.l<<" r: "<<n.r<<endl;
    //     cout<<"data: "<<n.data<<endl;
        
    // }
    for(int i = 0; i<q; i++){
        int a, b; cin>>a>>b;
        a--;
        cout<<query(a,b,0)<<endl;
    }
}