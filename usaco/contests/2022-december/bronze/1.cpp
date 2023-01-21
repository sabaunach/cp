#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (auto &x: v) cin >> x;
    sort(v.begin(), v.end());
    int mx = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        int pr = (n-i)*(v[i]);
        if (mx < pr) {
            idx = i;
            mx = pr;
        }
    }
    cout << mx << " " << v[idx] << "\n";
}