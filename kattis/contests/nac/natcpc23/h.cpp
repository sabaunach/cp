/* https://vjudge.net/contest/556429#problem/H
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

typedef vector<int> vi;

int main() {
    ll n, c; cin >> n >> c;
    vector<ll> t(n), d(n);
    rep(i,0,n) cin >> t[i] >> d[i];

    vector<ll> depth(n);
    ll max_depth = 0, sum_depth = 0;
    rep(i,0,n) {
        depth[i] = t[i]/d[i] + (bool)(t[i]%d[i]);
        chmax(max_depth, depth[i]);
        sum_depth += depth[i];
    }

     if (c >= n) {
        ll x = 0;
        for (ll b = 1LL<<62; b > 0; b>>=1) {
            ll sum = 0;
            rep(i,0,n) {
                // t[i]-d[i]*(x+b) >= 0
                if ((__uint128_t)d[i]*(x+b) <= t[i]) {
                    sum += t[i] - d[i]*(x+b) + 1;
                }
            }
            if (sum > c) x += b;
        }
        cout << x << "\n";
        return 0;
     }

    map<ll, vector<int>> md;
    vector<ll> cost(n, -1);
    rep(i,0,n) md[-depth[i]].pub(i);

    ll sum = 0;
    while (max_depth >= sum_depth/c + (bool)(sum_depth%c)) {
        vector<int> v;
        fore(x, md.begin()->se) v.pub(x); md.erase(md.begin());
        fore(x, v) md[-max_depth+1].pub(x);
        ll cur_sum = 0;
        fore(i, v) {
            cur_sum += abs(cost[i]);
            if (cost[i] == -1) cost[i] = (t[i] % d[i]) ? t[i] % d[i] : d[i];
            else cost[i] = d[i];
        }
        if (sum + cur_sum > c) {
            break;
        }
        sum += cur_sum;
        max_depth--;
        sum_depth -= v.size();
    }
    sum_depth -= (c - sum);

    cout << max(max_depth, sum_depth/c + (bool)(sum_depth%c)) << "\n";

}
