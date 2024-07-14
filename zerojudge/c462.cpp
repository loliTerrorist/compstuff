#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int k; cin>>k;
    string input; cin>>input;
    int anchor = 0;
    int maxlen = 0;
    int currlen = 0;
    int currindex = -1;
    bool ccase = isupper(input[0]);
    while(anchor<input.size()&&currindex<input.size()){
        bool ok = 1;
        for(int i = 0; i<k; i++){
            currindex++;
            if(currindex>=input.size()){
                ok=0;
                break;
            }else
            if(isupper(input[currindex])!=ccase){
                ok = 0;
                anchor = currindex;
                currlen = 0;
                currindex = anchor-1;
                break;
                
            }else{

            }
        }
        if(ok){
            currlen+=k;
            ccase = !ccase;
        }else{
            ccase = isupper(input[anchor]);
        }
        maxlen = max(maxlen, currlen);
    }
    cout<<maxlen<<endl;
}