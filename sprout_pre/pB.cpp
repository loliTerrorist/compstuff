#include <bits/stdc++.h>

#define pb push_back
#define endl "\n"
#define ll long long
using namespace std;
ll frac(int x){
    int ans = 1;
    if(x<=1) return 1;
    if(x%2){
        return 2*x*pow(frac((x-1)/2),2);
    }else{
        return 2*pow(frac(x/2),2);
    }
}
void printvec(vector<string> vec){
    for(auto s:vec){
        cout<<s<<endl;
    }
}
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    string p; cin>>p;
    int n, q; cin>>n>>q;
    string s; cin>>s;
    // int times = 0;
    // string abet =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // vector<int> forward(26);
    int mod = 0;
    vector<string> chart;
    chart.pb(p);
    string pcopy = p;
    do{
        mod++;
        for(int i = 0; i<p.size();i++){
            pcopy[i] = p[pcopy[i]-'A'];
        }
        chart.pb(pcopy);
    }while(pcopy!=p);
    // cout<<"chart: "<<endl;
    // printvec(chart);
    // cout<<"chart"<<endl;
    for(int i = 0; i<q; i++){
        char ans;
        int ti, xi; cin>>ti>>xi;
        string sp = s;
        
        // for(int j = 0; j<n; j++){
        //     sp[j] = sp[j]-'A';
            
        // }
        // for(int j = 1; j<=ti;j++){
        //     for(int k = 0; k<n; k++){
        //         sp[k]=p[sp[k]]-'A';
        //     }
        // }
        // ans = (sp[xi-1]+'A');
        if(ti==0){
            ans = sp[xi-1];
        }else{
            ans = chart[(ti-1)%mod][sp[xi-1]-'A'];
        }
        cout<<ans<<endl;
    }

}