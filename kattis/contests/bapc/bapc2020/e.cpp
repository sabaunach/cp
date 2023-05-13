#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<vector<pair<int, int>>> adj;
vector<unordered_map<int, int>> adj_g;
const int MAX_P = 100;
vector<int> vis;
vector<bitset<MAX_P>> memo;
int mx = 0;
int n,m,P,g;
bitset<MAX_P> dfs(int v, int d = 0) {
    bitset<MAX_P> res = memo[v];
    if (vis[v]++) return memo[v];
    for (auto[c,w]: adj[v]) {
        auto c_res = dfs(c,d+w);
        res |= c_res;
    }
    int p = res.count();
    mx = max(mx, d*p - g*p);
    return memo[v] = res;
}

int32_t main() {
    cin >> n >> m >> P >> g;
    adj.resize(n); adj_g.resize(n);
    vis.resize(n); memo.resize(n);
    for (int i = 0; i < P; i++) {
        int x; cin >> x;
        memo[x-1].set(i);
    }
    for (int i = 0; i < m; i++) {
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        adj_g[a][b] = c;
        adj_g[b][a] = c;
    }

    vector<int> seen(n);
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, -1});

    int cost = 0;
    while (!pq.empty()) {
        auto[d, v, p] = pq.top(); pq.pop();
        if (seen[v] != 0 && d < seen[v]) continue;
        if (p != -1) {
            adj[p].emplace_back(v, adj_g[v][p]);
        }
        if (seen[v] == 0) {
            cost += -d*memo[v].count();
            for (auto [u, w]: adj_g[v])
                if (!seen[u] && u != 0)
                    pq.emplace(d - w, u, v);
        }
        seen[v] = d;
    }

    dfs(0);
    cout << cost - mx << "\n";
}