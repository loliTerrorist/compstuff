#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
struct node{
    int num;
    node *next;
    node *prev;
    
};
signed main(){
    int n; cin>>n;
    vector<node> childs(n);
    for(int i = 0; i<n; i++){
        childs[i].num = i+1;
        childs[i].next = &childs[(i+1)%n];
        childs[i].prev = &childs[(i-1+n)%n];
    }
    auto it = &childs[n-1];
    for(int i = 0; i<n; i++){
        it = (*it).next;
        it = (*it).next;
        cout<<(*it).num<<endl;
        auto prevchild = (*it).prev;
        auto nextchild = (*it).next;
        (*prevchild).next = (*it).next;
        (*nextchild).prev = (*it).prev;
        // (*it).prev = nullptr;
        // (*it).next = nullptr;
    }

    
}