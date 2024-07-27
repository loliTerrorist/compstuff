#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
    int n, k; cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    multiset<int> small;
    multiset<int> large;
    /*
    maintain 2 multiset, one stores the smaller half, and one stores the bigger half.
    k/2 <= size of small <= (k+1)/2, (k-1)/2 <= size of large <= k/2
    the medium is the largest num in small
    when we insert a number:
        if the number is greater than the medium:
            insert number into large
            if size of large excedes k/2
                move smallest element in large to small
        vice versa
    */
    auto in = [&](int val){
        if(small.size()==0){
            small.insert(val);
            return;
        }
        int medium = *small.rbegin();
        if(val>medium){
            large.insert(val);
            int aa = *large.begin();
            if(large.size()>k/2){
                small.insert(*large.begin());
                large.erase(large.find(*large.begin()));
            }
        
        }else{
            small.insert(val);
            int aa = *small.rbegin();
            if(small.size()>(k+1)/2){
                large.insert(*small.rbegin());
                small.erase(small.find(*small.rbegin()));
            }
        }
    };
    auto out = [&](int val){
        int medium = *small.rbegin();
        if(val>medium){
            large.erase(large.find(val));
            if(large.size()<(k-1)/2){
                large.insert(*small.rbegin());
                small.erase(small.find(*small.rbegin()));
            }
        }else{
            small.erase(small.find(val));
            if(small.size()<k/2){
                small.insert(*large.begin());
                large.erase(large.find(*large.begin()));
            }
        }
    };
    small.insert(arr[0]);
    for(int i = 1; i<k; i++){
        in(arr[i]);
    }
    
    for(int i = k; i<n; i++){
        cout<<*small.rbegin()<<' ';
        out(arr[i-k]);
        in(arr[i]);
    }
    cout<<*small.rbegin()<<endl;
}