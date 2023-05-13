#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;
vector<int> roots, root_nodes, component_sz;
vector<vector<int>> adj_scc, adj_scc_rev;
vector<int> sn;
int MOD = 1e9+7;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int dfs3(int v) {
    if (sn[v]) return sn[v];
    int t = 1;
    for (auto c : adj_scc_rev[v])
        (t *= (dfs3(c)+1)) %= MOD;
    return sn[v] = t;
}

int32_t main() {

    int n; cin >> n;

    adj.resize(n); adj_rev.resize(n);
    for (int i = 0; i < n; i++) {
        int y; cin >> y; y--;
        adj[i].push_back(y);
        adj_rev[y].push_back(i);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());
    roots.resize(n);
    adj_scc.resize(n);
    adj_scc_rev.resize(n);
    component_sz.resize(n);
    sn.resize(n);

    for (auto v : order)
        if (!used[v]) {
            dfs2(v);
            int sz = 0;
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
            component_sz[root] = sz;

            component.clear();
        }


    for (int v = 0; v < n; v++)
        for (auto u : adj[v]) {
            int root_v = roots[v],
                    root_u = roots[u];

            if (root_u != root_v) {
                adj_scc[root_v].push_back(root_u);
                adj_scc_rev[root_u].push_back(root_v);
            }
        }

    for (int v = 0; v < root_nodes.size(); v++) {
        dfs3(root_nodes[v]);
    }

    int tot = 1;
    for (int v = 0; v < root_nodes.size(); v++) {
        if (adj_scc[root_nodes[v]].empty()) {
            (tot *= (sn[root_nodes[v]]+1)) %= MOD;
        }
    }
    cout << (tot-1+MOD)%MOD << endl;
}