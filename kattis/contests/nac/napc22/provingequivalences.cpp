#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;
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
    for (auto u: adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int solve() {
    int n, m; cin >> n >> m;
    adj.resize(n); adj.clear(); adj_rev.resize(n); adj_rev.clear();
    order.clear(); component.clear();
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj_rev[b-1].push_back(a-1);
    }
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());
    vector<int> roots(n, 0), root_nodes;
    vector<vector<int>> adj_scc(n), adj_scc_rev(n);
    for (auto v: order)
        if (!used[v]) {
            dfs2(v);
            int root = component.front();
            for (auto u: component) roots[u] = root;
            root_nodes.push_back(root);
            component.clear();
        }
    for (int v = 0; v < n; v++) {
        for (auto u: adj[v]) {
            int root_v = roots[v], root_u = roots[u];
            if (root_u != root_v) {
                adj_scc[root_v].push_back(root_u);
                adj_scc_rev[root_u].push_back(root_v);
            }
        }
    }
    // connect sink nodes to source nodes in condensation graph
    // answer is max(sinks, sources)
    // standalone SCCs count as sinks and sources
    if (root_nodes.size() == 1) return 0;
    int sinks = 0, sources = 0;
    for (auto i: root_nodes) {
        if (adj_scc[i].empty())
            sinks++;
        if (adj_scc_rev[i].empty())
            sources++;
    }
    return max(sinks, sources);
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << endl;
}