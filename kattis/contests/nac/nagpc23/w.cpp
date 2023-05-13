/*
 * https://vjudge.net/contest/553125#problem/W
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

vector<vector<ll>> cache;
int m;
ll solve(int t, int p) {
    if (cache[p][t]) return cache[p][t];
    ll a = 1, x = 1;
    rep(e, 1, p+1) {
        x*=m;
        rep(j, 1, t/x+1) a += solve(t-j*x, e-1);
    }
    return cache[p][t] = a;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int k,n;
        cin>>k>>m>>n;
        cache.assign(10, vector<ll>(10001));
        int p = 0, x = 1; while (x*m <= n) p++, x*=m;
        cout << k << " " << solve(n, p) << "\n";
    }
}