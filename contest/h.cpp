#include <bits/stdc++.h>

using namespace std;
void ask(string s){
    cout<<"? "<<s<<flush;
}
void quess(string s){
    cout<<"! "<<s<<flush;
}
vector<int> receive(){
    int s;
    cin>>s;
    vector<int> ret(s);
    for(int i = 0; i<s; i++){
        cin>>ret[i];
    }
}
signed main(){
    int len = 0;
    string all = "abcdefghijklmnopqrstuvwxyz";
    ask(all);
    vector<int> firstq = receive();
    for(int i = 0; i<firstq.size(); i++){
        len = max(len, firstq[i]);
    }
    

}