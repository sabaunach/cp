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

using vi = vector<int>;
struct DSU {
    vi v; explicit DSU(int n) : v(n, -1) {}
    int get(int x) { return v[x] < 0 ? x : v[x] = get(v[x]); }
    bool same(int x, int y) { return get(x) == get(y); }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (v[x] < v[y]) swap(x, y);
        v[y] += v[x]; v[x] = y;
        return true;
    }
};

struct edge {
    int u,v; ll c;
    bool red;
};
int main() {
    int n,m,k,w;
    vector<edge> edges;
    cin>>n>>m>>k>>w;
    vector<bool> s(n);
    rep(i,0,k) { int x; cin >> x; s[x-1]=true; }
    rep(i,0,m) {
        int u,v; ll c; cin>>u>>v>>c;
        u--; v--;
        if (s[u] ^ s[v]) edges.pub({u,v,c,true});
        else edges.pub({u,v,c,false});
    }

    auto f = [&](ll lam) {
        ll cost = 0;
        fore(e, edges) if (e.red) e.c -= lam;
        sort(all(edges), [] (auto&a, auto&b) {
            return a.c < b.c; });
        DSU dsu(n);
        fore(e, edges) {
            if (dsu.unite(e.u, e.v))
                cost += e.c;
        }
        fore(e, edges) if (e.red) e.c += lam;
        if (-dsu.v[dsu.get(0)] < n) { cout << "-1\n"; exit(0); }
        return cost + lam*w;
    };
    ll l = -200000, r = 200000;
    while (l+1 < r) e{
        ll x1 = (l+r)/2-1, x2 = x1+1;
        auto f_x1 = f(x1), f_x2 = f(x2);
        if (f_x1 < f_x2)
            l = x2;
        else if (f_x1 > f_x2)
            r = x1;
        else { cout << f_x1 << "\n"; exit(0); }
    }
    if (l == -200000 || r == 200000) { cout << "-1\n"; exit(0); }
    cout << max({f(l), f(r)}) << "\n";
}