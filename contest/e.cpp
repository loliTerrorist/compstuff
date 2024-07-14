#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define float double
using namespace std;
/*
{
    {a, b, c}
    {d, e, f}
}
{
    {a, b}
    {c, d}
}
*/
vector<vector<float> > febmat = {{0.5, 0.5},{1, 0}};

vector<vector<float> > mult(vector<vector<float> > a, vector<vector<float> > b){
    vector<vector<float> > ret(2, vector<float>(2, 0));
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            ret[i][j] = a[i][0]*b[0][j]+a[i][1]*b[1][j];
        }
    }
    return ret;
}

vector<vector<float> > fastpow(vector<vector<float> > a, int n) {
    if(n==1) return febmat;
    if(n%2==0){
        vector<vector<float> > ret = fastpow(febmat, n/2);
        return mult(ret, ret);
    }else{
        vector<vector<float> > ret = fastpow(febmat, n/2);
        return mult(ret, mult(febmat,ret));
    }

    
}

signed main(){
    // vector<int> ormat = {1, 1};
    // int n; cin>>n;
    // vector<vector<int> > fpm = fastpow(febmat, n);
    // vector<int> ans = {
    //     ormat[0]*fpm[0][0]+ormat[0]*fpm[0][1], ormat[0]*fpm[1][0]+ormat[1]*fpm[1][1]
    // };
    // cout<<ans[0]<<' '<<ans[1]<<endl;
    int n; cin>>n;
    if(n==1) cout<<100<<' '<<0<<endl;
    else if(n==2) cout<<0<<' '<<100<<endl;
    else{
        vector<vector<float> > fpm = fastpow(febmat, n-2);
        cout<<fixed<<setprecision(8)<<fpm[0][1]*100<<' '<<fpm[0][0]*100<<endl;
    }
    // }else{
    //     cout<<33.333333<<' '<<66.666667<<endl;
    // }
    
}