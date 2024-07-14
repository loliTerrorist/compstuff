#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
/*
First we sort the time array by small to big
Notice that if the last value in the array is bigger than the sum of previous values,
when A is reading the last book, B would be able to finish all previous books,
therefore yielding the total time needed, times[n-1]*2.

If the sum of previous values is larger than the last one, A can read all previous books,
while B reads the last. When A finishes, he reads the last book, giving a total time of the sum
of all values in the array.
*/
signed main(){
    int n; cin>>n;
    vector<int> times = vector<int>(n);
    int sumtimes = 0;
    for(int i = 0; i<n; i++){
        cin>>times[i];
        sumtimes+=times[i];
    }
    sort(times.begin(), times.end());
    if(2*times[n-1]>sumtimes) cout<<2*times[n-1]<<endl;
    else{
        cout<<sumtimes<<endl;
    }
}
