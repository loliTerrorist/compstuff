#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> val(n + 2), pos(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    val[n + 1] = n + 1;

    for (int i = 0; i <= n + 1; i++) {
        pos[val[i]] = i;
    }

    int sum = 1;
    for (int i = 1; i <= n; i++) {
        if (pos[i] < pos[i - 1]) sum++;
    }

    int a, b;
    while (q--) {
        cin >> a >> b;
        a = val[a], b = val[b];

        vector<int> check;
        check.push_back(a), check.push_back(a + 1), check.push_back(b), check.push_back(b + 1);
        sort(check.begin(), check.end());
        check.resize(unique(check.begin(), check.end()) - check.begin());
        // for(auto v: check){
        //     cout<<v<<' ';
        // }
        // cout<<endl;
        int before, after;
        before = after = 0;
        for (auto& n: check) {
            if (pos[n] < pos[n - 1]) before++;
        }

        swap(pos[a], pos[b]);
        swap(val[pos[a]], val[pos[b]]);

        for (auto& n: check) {
            if (pos[n] < pos[n - 1]) after++;
        }

        sum += after - before;

        cout << sum << '\n';
    }
}