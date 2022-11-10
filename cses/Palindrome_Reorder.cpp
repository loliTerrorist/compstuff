#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    map<char, int> m;
    for(char c: s){
        if(m.count(c)){
            m[c]++;
        }else{
            m[c]=1;
        }
    }
    int oddcount = 0;
    int oddkey = -1;
    for(auto const  &s: m){
        if(s.second%2){
            oddcount++;
            if(oddcount>1) break;
            oddkey = s.first;
        }
    }
    if(oddcount>1){
        cout<<"NO SOLUTION"<<endl;
    }else {
        if(s.length()%2==0&&oddcount>0){
            cout<<"NO SOLUTION"<<endl;
        }
        for(auto const &s: m){
                for(int i = 0; i<s.second/2; i++){
                    cout<<s.first;
                }
                
            }

            if (oddcount!=0) cout<<char(oddkey);

            for(auto s = m.rbegin(); s!=m.rend(); s++){
                for(int i = 0; i<(*s).second/2; i++){
                    cout<<(*s).first;
                }
            }
            cout<<endl;
    }
    
}