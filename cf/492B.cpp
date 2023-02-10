#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l; cin>>n>>l;
    int dis=0;
    float d;
    vector<int> pos(n);
    for(int i = 0; i<n; i++){
        cin>>pos[i];
    }
    sort(pos.begin(), pos.end());
    dis = 2*max(pos[0], l-pos[n-1]);
    for(int i = 0; i<n-1; i++){
        dis = max(dis,pos[i+1]-pos[i]);
    }
       // d = max((dis)/2., max(pos[0], l-pos[n-1]));
    // cout<<dis/2.<<endl;
    printf("%.10f\n",dis/2.);
}
