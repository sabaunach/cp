/* https://vjudge.net/contest/556429#problem/J
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back

#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define sz(x) int((x).size())

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
    int n; cin >> n;
    vector<pair<ll, int>> v(n);
    rep(i,0,n) {
        ll x; cin >> x;
        v[i] = {x, i};
    }

    // ascending order of # bits set
    sort(all(v), [] (auto &a, auto &b) {
        return __builtin_popcount(a.fi) > __builtin_popcount(b.fi); });

    list<pair<ll, int>> b(v.begin(), v.end());
    reverse(all(b));

    fore(x,v) cout << x.fi << " "; cout << "\n";
    fore(x,b) cout << x.fi << " "; cout << "\n";

    vector<ll> ans(n);

    rep(i,0,n) {
        auto it = b.begin();
        for (; it != b.end(); it++) {
            if (!(v[i].fi & it->fi)) {
                ans[v[i].se] = it->se;
                cout << v[i].fi << " " << it->fi << "\n";
                b.erase(it);
                break;
            }
        }
        assert(it != b.end());
    }

    rep(i,0,n) cout << ans[i] << "\n";
}