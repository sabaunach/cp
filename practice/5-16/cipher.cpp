#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> v(n); fore(x, v) cin >> x;

    int s; cin >> s;

    int sz_l = n/2, sz_r = n/2 + n%2;
    map<int, int> l, r;
    rep(m,0,(1<<sz_l)) {
        int sum = 0;
        rep(b,0,sz_l) {
            if (1<<b & m) sum += v[b];
        }
        l[sum] = m;
    }
    rep(m,0,(1<<sz_r)) {
        int sum = 0;
        rep(b,0,sz_r) {
            if (1<<b & m) sum += v[sz_l + b];
        }
        r[sum] = m;
    }
    for(auto&[v,m]: l) {
        if (s-v >= 0 && r.count(s-v)) {
            rep(b,0,sz_l) cout << (bool)(1<<b & m);
            int m_r = r[s-v];
            rep(b,0,sz_r) cout << (bool)(1<<b & m_r);
            return 0;
        }
    }
}