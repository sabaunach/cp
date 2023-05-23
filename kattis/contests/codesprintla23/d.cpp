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

typedef pair<ll, int> pli;
typedef pair<pli, int> pq_t;

vector<vector<pli>> adj;
int m,n;

pair<ll, int> djik(ll b) {
    priority_queue<pq_t, vector<pq_t>, greater<>> pq;
    vector<bool> vis(sz(adj));
    rep(i,0,n) { 
        pq.push({{0, 0}, m+i*m});
    }
    pli res;
    vector<pli> cost(sz(adj), {LLONG_MAX, INT_MAX});
    while(!pq.empty()) {
        auto [v_c, v] = pq.top(); pq.pop();
        if ((v - m) % m == m - 1) {
            res = v_c;
            break;
        }
        if (vis[v])
            continue;
        vis[v] = true;
        for (auto[w, u]: adj[v]) {
            pli u_c = {v_c.fi + (w == -1 ? b : w), v_c.se + (w == -1)};
            if (vis[u] || u_c >= cost[u]) continue;
            pq.push({u_c, u});
            cost[u] = u_c;
        }
    }
    res.fi /= 2; res.se /= 2;
    return res;
}

pair<pli, int> ser(int num_blu, int l = -1, int r = 500001) {
    if (l + 1 >= r)
        return {djik(l+1), l+1};

    int m = (l+r)/2;
    if (djik(m).se <= num_blu) {
        return ser(num_blu, l, m);
    } else {
        return ser(num_blu, m, r);
    }
}


int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    ll a; cin >> a;
    adj.resize(m + m*n);
    rep(i,0,n) {
        int s; cin >> s;
        int prev;
        rep(j,0,s) {
            int st; cin >> st; st--;
            int cur = m + i*m + st;
            adj[cur].pub({-1, st});
            adj[st].pub({-1, cur});
            if (j > 0) {
                adj[prev].pub({a*2, cur});
                adj[cur].pub({a*2, prev});
            }
            prev = cur;
        }
    }
    map<int, pli> mp;
    rep(i,0,101) {
        auto[pr, B] = ser(i);
        auto[cost, blu] = pr;
        mp[B] = pr;
    }
    int t; cin >> t;
    while (t--) {
        int b; cin >> b;
        auto it = prev(mp.upper_bound(b));
        cout << it->se.fi + (b - it->fi) * it->se.se << "\n";
    }
}