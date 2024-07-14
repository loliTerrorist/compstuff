#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
struct node{
    node *left = nullptr; node *right = nullptr; int val;
    node *parent = nullptr;
};

void add(int n, node &nd, node &newnd){
    if(n<nd.val){
        if(nd.left==nullptr){
            newnd.parent = &nd; 
            newnd.val = n;
            nd.left = &newnd;
        }else{
            add(n, *(nd.left), newnd);
        }
    }else{
        if(nd.right==nullptr){
            newnd.parent = &nd;
            newnd.val = n;
            nd.right = &newnd;
        }else{
            add(n, *(nd.right), newnd);
        }
    }
}

void dfs(node* nd){
    if(nd!=nullptr){
        dfs(nd->left);
        dfs(nd->right);
        cout<<nd->val<<endl;
    }
}

signed main(){
    int n; cin>>n;
    vector<node> nodevec(n);
    node startingnd;
    nodevec[0] = startingnd;
    for(int i = 0; i<n; i++){
        int in; cin>>in;
        if(i==0){
            startingnd.val = in;
        }else{
            node newnd; 
            nodevec[i] = newnd;
            add(in, startingnd, nodevec[i]);
        }
    }
    
    dfs(&startingnd);
}