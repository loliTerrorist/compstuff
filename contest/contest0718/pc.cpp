#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    vector<int> a(n); 
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<int> s(2*n);
    //s[-1] = 0;
    s[0] = a[0];
    set<int> numbers;
    map<int,int> numbertimes;
    numbertimes[s[0]] = 0;
    auto INSERT = [&](int num){
        numbers.insert(num);
        numbertimes[num]++;
    };
    auto DELETE = [&](int num){
        if(numbertimes[num]>0){
            numbertimes[num]--;
        }
        if(numbertimes[num]<=0){
            numbers.erase(num);
        }
    };

    
    for(int i = 1; i<2*n; i++){
        s[i] = s[i-1]+a[i%n];
        if(!numbertimes.count(s[i])){
            numbertimes[s[i]] = 0;
        }
        
    }
    vector<int> maxdp(2*n, -1e7);
    vector<int> mindp(2*n, 1e7);
    
    int tempmax = -1e7;
    int tempmin = 1e7;
    for(int i = 0; i<n; i++){
        INSERT(s[i]);
        tempmax = max(tempmax, s[i]);
        tempmin = min(tempmin, s[i]);
    }
    maxdp[0] = tempmax;
    mindp[0] = tempmin;
    int ansmax = -1e6;
    int ansmin = 1e6;
    
    for(int i = 1; i<n; i++){
        DELETE(s[i-1]);
        INSERT(s[i-1+n]);
        cout<<*numbers.begin()<<endl;
        maxdp[i] = *numbers.begin()-s[i-1];
        mindp[i] = *numbers.end()-s[i-1];
    }
    for(int i = 0; i<n; i++){
        cout<<mindp[i]<<' '<<maxdp[i]<<endl;
    }

    

}