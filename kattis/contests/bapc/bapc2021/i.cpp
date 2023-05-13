#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define int long long

int32_t main() {
    int n; cin >> n;
    vector<int> t(n), s(n);
    for (auto &x: t) cin >> x; for (auto &x: s) cin >> x;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        if (s[i] == -1) continue;
        v.emplace_back(t[i], s[i]);
    }
    n = v.size();
    sort(v.begin(), v.end(), [] (auto &a, auto &b) { return a.se < b.se; });

    auto chk = [&] (int x) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i].fi;
            if (sum > v[i].se*x) {
                return false;
            }
        }
        return true;
    };

    int l = 0, r = 10000000000000LL + 1;
    while (l+1 < r) {
        int m = (l+r)/2;
        if (chk(m)) r = m;
        else l = m;
    }
    cout << r << "\n";
}