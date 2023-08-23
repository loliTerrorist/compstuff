#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int N, L, R;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        v.push_back({L, 1});
        v.push_back({R, -1});
    }
    sort(v.begin(), v.end());
    int now = 0, event = 0, ans = 0;
    for (int i = 0; i <= 1e7; i++) {
        while (now < (int)v.size() && v[now].first == i) {
            event += v[now].second;
            now++;
        }
        if (event > 0) {
            ans+=event*(event-1)/2;
        }
    }
    cout << ans << "\n";
    return 0;
}
