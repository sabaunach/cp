#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

ll cediv(ll a, ll b) {
    return (a/b)+((bool)a%b);
}

int main() {
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for (auto&[p,d]: v) cin >> p >> d;


    sort(v.begin(), v.end(), [] (auto a, auto b) { return (double)a.fi/a.se < (double)b.fi/b.se; });

    for (int i = 0; i < m; i++) v.pop_back();

    sort(v.begin(), v.end(), [] (auto a, auto b) { return a.se < b.se; });

    vector<ll> pre_p = {v[0].fi}, pre_d = {v[0].se};
    for (int i = 1; i < v.size(); i++) {
        pre_p.push_back(pre_p.back() + v[i].fi);
        pre_d.push_back(pre_d.back() + v[i].se);
    }

    function<ll(int)> f;
    f = [&] (int x) -> ll {
        if (x==-1) return 0;
        return min(cediv(f(x-1)+v[x].fi, , f(x-1));
    };
    for (auto [a,b]: v) cout << a << " " << b << "\n";

    ll res = 0;
    ll num = 0, dem = 0; for (auto&[a,b]: v) {
        num += a;
        dem = max(dem, b);
        res = max(res, cediv(a, b));
    }
    res = max(res, cediv(num, dem));
    cout << res << "\n";
}