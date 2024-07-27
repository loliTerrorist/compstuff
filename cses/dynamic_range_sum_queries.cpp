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
            st[index].data = st[lson].data+st[rson].data;
        }
    };
    function<int(int,int,int)> query = [&](int l, int r, int index){
        int mid = (st[index].l+st[index].r)/2;
        if(l==st[index].l&&r==st[index].r){
            return st[index].data;
        }else
        if(r<=mid){
            int temp = query(l, r, st[index].lson);
            // cout<<"query "<<l<<" "<<r<<": "<<temp<<endl;
            return temp;
        }else
        if(l>=mid){
            int temp = query(l, r, st[index].rson);
            // cout<<"query "<<l<<" "<<r<<": "<<temp<<endl;
            return temp;
        }else{
            int temp = query(l, mid, st[index].lson)+query(mid, r, st[index].rson);
            // cout<<"query "<<l<<" "<<r<<": "<<temp<<endl;
            return temp;
        }
    };
    function<void(int,int,int,int)> change = [&](int l, int r, int index, int value){
        int mid = (st[index].l+st[index].r)/2;
        int lson = st[index].lson;
        int rson = st[index].rson;
        if(l==st[index].l&&r==st[index].r){
            st[index].data = value;
        }else
        if(r<=mid){
            change(l, r, lson, value);
            st[index].data = st[lson].data+st[rson].data;
        }else
        if(l>=mid){
            change(l, r, rson, value);
            st[index].data = st[lson].data+st[rson].data;
        }
    };
    build(0, n, 0);
    
    for(int i = 0; i<q; i++){
        int command_type, a, b;
        cin>>command_type>>a>>b; 
        if(command_type==1){
            a--;
            change(a, a+1, 0, b);
        }else{
            a--;
            cout<<query(a,b,0)<<endl;
        }
    }
}