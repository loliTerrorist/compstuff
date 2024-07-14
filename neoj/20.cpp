#include <bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;

signed main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int t; cin>>t;
    for(int tt = 1; tt<=t; tt++){
        int n; cin>>n;
        vector<set<int> > groups(n);
        vector<int> persongroup(1e6, -1);
        for(int i = 0; i<n; i++){
            int temp; cin>>temp;
            while(temp--){
                int temp2; cin>>temp2;
                groups[i].insert(temp2);
                persongroup[temp2] = i;
            }
        }
        vector<int> insertpoint(n,-1);
        vector<int> vqueue(1e6,-1);
        int m; cin>>m;
        vector<int> ans;
        int queueend = 0;
        int queuestart = 0;
        while(m--){
            string operation; cin>>operation;
            if(operation=="ENQUEUE"){
                int person; cin>>person;
                bool ingroup = 0;
                
                if(persongroup[person]!=-1){
                    if(insertpoint[persongroup[person]]!=-1){
                        vqueue[insertpoint[persongroup[person]]] = person;
                        insertpoint[persongroup[person]]++;
                    }else{
                        vqueue[queueend] = person;
                        insertpoint[persongroup[person]] = queueend+1;
                        queueend+=groups[persongroup[person]].size();
                    }
                }
                
                if(persongroup[person]==-1){
                    vqueue[queueend] = person;
                    queueend++;
                }
                // for(int i = 0; i<n; i++){
                //     if(groups[i].count(person)){
                //         ingroup = 1;
                //         if(insertpoint[i]!=-1){
                //             vqueue[insertpoint[i]] = person;
                //             insertpoint[i]++;

                //         }else{
                //             vqueue[queueend] = person;
                //             insertpoint[i] = queueend+1;
                //             queueend+=groups[i].size();
                //         }
                //         break;
                //     }
                // }
                // if(ingroup==0){
                //     vqueue[queueend] = person;
                //     queueend++;
                // }
            }else if(operation == "DEQUEUE"){
                if(vqueue[queuestart]!=-1){
                    ans.push_back(vqueue[queuestart]);
                    queuestart++;
                }else{
                    while(vqueue[queuestart]==-1){
                    queuestart++;
                    }
                    ans.push_back(vqueue[queuestart]);
                    queuestart++;
                }
                
                
                
                
                
                
                
                
            }
            // for(int i = queuestart; i<=queueend; i++){
            //     cout<<vqueue[i]<<' ';
            // }cout<<endl;
        
        }
        cout<<"Line #"<<tt<<endl;
        for(auto aaa: ans){
            cout<<aaa<<endl;
        }
    }
}