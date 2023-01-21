#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second

#define int long long
int32_t main() {
    int n,s; cin >> s >> n;
    vector<pair<int, char>> v(n);
    for (auto &x: v) cin >> x.first >> x.second;
    sort(v.begin(), v.end());
    int a = 0, b = 0, t;
    for (int i = 0; i < n;) {
        t = v[i].fi;
        for (; v[i].fi == t; i++) {
            a += v[i].se == 'y';
            b++;
        }
        if (a>t || b>s*t) {
            cout << "No\n"; return 0;
        }
    }
    cout << "Yes\n";
}