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

int n,m,k,w;
vector<tuple<int, int, int>> s_e, n_e;
pair<int, ll> step(ll lambda, bool last = false) {
    // kruskal's, prioritize normal edges (if last, until # white edges = n-1-w)
    priority_queue<tuple<int, int, int, int>> pq;
    for(auto&[u,v,c]: n_e) pq.emplace(-c,1,u,v);
    for(auto&[u,v,c]: s_e) pq.emplace(-(c-lambda),0,u,v);

    DSU dsu(n); int s_u = 0, n_u = 0; ll weight = 0;
    while (!pq.empty() && !(last && n-1-w == n_u)) {
        auto[c,s,u,v] = pq.top(); pq.pop();
        if (dsu.unite(u,v)) {
            s_u+=!s; n_u+=s;
            weight-=c;
        }
    }
    if (last) {
        // now prioritize special edges
        pq = {};
        for(auto&[u,v,c]: n_e) pq.emplace(-c,0,u,v);
        for(auto&[u,v,c]: s_e) pq.emplace(-(c-lambda),1,u,v);
        while (!pq.empty()) {
            auto[c,s,u,v] = pq.top(); pq.pop();
            if (dsu.unite(u,v)) {
                s_u+=s; n_u+=!s;
                weight-=c;
            }
        }
    }
    if (-dsu.v[dsu.get(0)] < n) {
        cout << "-1";
        exit(0);
    }
    return {s_u, weight+lambda*s_u};
}

int main() {
    cin>>n>>m>>k>>w;
    vector<bool> s(n);
    rep(i,0,k) { int x; cin >> x; s[x-1]=true; }
    rep(i,0,m) {
        int u,v,c; cin>>u>>v>>c;
        u--; v--;
        if (s[u] ^ s[v]) s_e.emplace_back(u,v,c);
        else n_e.emplace_back(u,v,c);
    }

    // [l,r)
    ll l = -200000, r = 200000;
    int used; ll weight;
    while (l+1<r) {
        ll t = (l+r)/2;
        auto pr = step(t);
        used = pr.fi; weight = pr.se;
        // cout << l << " " << r << " " << used << " " << weight << "\n";
        if (used > w) {
            r = t;
        } else {
            l = t;
        }
    }
    auto pr = step(l, true);
    used = pr.fi; weight = pr.se;
    // cout << l << " " << r << " " << used << " " << weight << "\n";
    if (used == w) cout << weight;
    else cout << -1;
}