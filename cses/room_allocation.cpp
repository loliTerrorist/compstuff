#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
class comptimeroom{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first>b.first;
    }
};
struct operation{
    int start; int op; int index; int end;
};
signed main(){
    int n; cin>>n;
    vector<pair<int,int> > times(n);
    vector<operation> change;
    for(int i = 0; i<n; i++){
        cin>>times[i].first>>times[i].second;
        operation op1;
        op1.start = times[i].first;
        op1.end = times[i].second+1;
        op1.op = 1;
        op1.index = i;
        operation op2 = op1;
        op2.op = -1;
        change.push_back(op1);
        change.push_back(op2);
    }
    auto op_comp = [&](operation a, operation b){
        int timea; int timeb;
        if(a.op == 1) timea = a.start;
        else timea = a.end;
        if(b.op == 1) timeb = b.start;
        else timeb = b.end;
        if(timea==timeb){
            return a.op<b.op;
        }else{
            return timea<timeb;
        }
    };
    auto op_comp2 = [&](operation a, operation b){
        int timea; int timeb;
        if(a.op == 1) timea = a.start;
        else timea = a.end;
        if(b.op == 1) timeb = b.start;
        else timeb = b.end;
        if(timea==timeb){
            return a.op>b.op;
        }else{
            return timea<timeb;
        }
    };
    sort(change.begin(), change.end(), op_comp);
    int curr = 0;
    int k = 0;
    
    for(auto ichange: change){
        int ttime;
        if(ichange.op==1) ttime = ichange.start;
        else ttime = ichange.end;
        // cout<<"time: "<<ttime<<" op: "<<ichange.op<<" index: "<<ichange.index<<endl;
        curr+=ichange.op;
        k = max(k,curr);
    }
    cout<<k<<endl;
    stack<int> rooms;
    for(int i = 0; i<k; i++){
        rooms.push(i+1);
    }
    //pair {return time, return room}
    vector<int> roomsallocation(n);
    priority_queue<pair<int,int>, vector<pair<int, int> >, comptimeroom > pq;
    // sort(change.begin(), change.end(), op_comp2);
    for(auto ichange: change){
        if(ichange.op==1){
            int toproom = rooms.top();
            pq.push({ichange.end, toproom});
            rooms.pop();
            roomsallocation[ichange.index] = toproom;
        }else if(ichange.op==-1){
            rooms.push(pq.top().second);
            pq.pop();
        }

    }
    for(auto cccc: roomsallocation){
        cout<<cccc<<' ';
    }cout<<endl;
    

}