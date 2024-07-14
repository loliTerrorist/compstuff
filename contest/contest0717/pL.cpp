#include <bits/stdc++.h>

using namespace std;

signed main(){
    /*
    find repeating patterns
    ababacdcxx 3
    

    1. we have two options when considering a new character a[i]:
        (1) appending a[i] to end of current word
        (2) ending the current word, pushing it into words, creating a new word starting with a[i]
        
    2. if curr word is empty, (1)
    

    */
    string t; cin>>t;
    int d; cin>>d;
    vector<string> words;
    string curr = "";
    int index = 0;
    vector<int> dp;
    for(int i = 0; i<t.size(); i++){
        if(curr.size()==0){
            curr.push_back(t[i]);
            words.push_back(curr);
        }else{
            if(curr.size()<d){
                curr.push_back(t[i]);
                words.push_back(curr);
            }
        }

    }


}