#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct node{
    int l, r;
    int lson, rson;
    int data;
};
signed main(){
    int n, q; cin>>n>>q;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    vector<node> st(2*n);
    int counter = 0;
    function<void(int,int,int)> build = [&](int l, int r, int index){
        st[index].l = l;
        st[index].r = r;
        if(l==r-1){
            st[index].data = arr[l];
        }else{
            counter++;
            int lson = st[index].lson = counter;
            counter++;
            int rson = st[index].rson = counter;
            int mid = (l+r)/2;
            build(l, mid, lson);
            build(mid, r, rson);
            st[index].data = min(st[lson].data, st[rson].data);
        }

    };
    function<int(int,int,int)> query = [&](int l, int r, int index){
        int lson = st[index].lson;
        int rson = st[index].rson;
        int mid = (st[index].l+st[index].r)/2;
        if(l==st[index].l&&r==st[index].r){
            return st[index].data;
        }else
        if(r<=mid){
            return query(l, r, lson);
        }else
        if(l>=mid){
            return query(l, r, rson);
        }else{
            return min(query(l, mid, lson), query(mid, r, rson));
        }
    };
    function<void(int,int,int,int)> change= [&](int l, int r, int index, int value){
        int mid = (st[index].l+st[index].r)/2;
        int lson = st[index].lson;
        int rson = st[index].rson;
        if(l==st[index].l&&r==st[index].r){
            st[index].data = value;
        }else
        if(r<=mid){
            change(l, r, lson, value);
            st[index].data = min(st[lson].data, st[rson].data);
        }else
        if(l>=mid){
            change(l, r, rson, value);
            st[index].data = min(st[lson].data, st[rson].data);
        }
    };
    build(0, n, 0);
    for(int i = 0; i<q; i++){
        int t, a, b; cin>>t>>a>>b;
        a--;
        if(t==1){   
            change(a,a+1,0,b);
        }else{
            cout<<query(a, b, 0)<<endl;
        }
    }
}