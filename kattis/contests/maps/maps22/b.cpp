#include <bits/stdc++.h>

using namespace std;

template<class T>
ostream& operator<<(ostream& os, unordered_multiset<T>& v) {
    for(auto& i : v) os << i << " ";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto& i : v) os << i << " ";
    return os;
}

typedef long long ll;

vector<vector<int>> adj, adj_rev, roots_rev;
vector<bool> used;
vector<int> order, component, val;
vector<ll> sums;

vector<int> roots;
vector<int> root_nodes;
vector<vector<int>> adj_scc, adj_scc_rev;

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

ll dfs3(int v, unordered_map<int, int> & vals) {
    ll ans = 0;
    vals[val[v]]++;
    if (roots[v] == v) {
        for (auto x: roots_rev[v])
            if (x != v)
                vals[val[x]]++;
        ans = vals.size()    * (roots_rev[v].size());
    }
    for(auto& u : adj_scc_rev[v])
        ans += dfs3(u, vals);

    if (!(--vals[val[v]])) vals.erase(val[v]);
    return ans;
}

int main() {
    int n; cin >> n;
    val = vector<int>(n);
    for (auto &x: val) cin >> x;

    adj = vector<vector<int>>(n);
    adj_rev = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        int nxt = i + val[i];
        if (nxt >= 0 && nxt < n) {
            adj[i].push_back(nxt);
            adj_rev[nxt].push_back(i);
        }
    }

    // SCC stuff
    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    // condensation graph stuff

    roots = vector<int>(n, 0);
    roots_rev = vector<vector<int>>(n);
    adj_scc = vector<vector<int>>(n);
    adj_scc_rev = vector<vector<int>>(n);

    for (auto v : order)
        if (!used[v]) {
            dfs2(v);
            int root = component.front();
            for (auto u : component) {
                roots[u] = root;
                    roots_rev[root].push_back(u);
            }
            root_nodes.push_back(root);

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

    // reverse edges
    // top sort
    // (so that we go from bottom to top)
    // compute sum as we go

    ll totsum = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<int,int> set = {};
        if (adj_scc[i].empty())
            totsum += dfs3(i, set);
    }
    cout << totsum << endl;
}
// 0 1 2 3
// 1 2 3 4
// root_nodes = {0, 1, 2, 3}

// 0  1  2  3  4  5  6  7
// 7  5  4  2  13 -2 -3 6
//
// 3 2, 3 -2, 5 2, 5 -2     4
// 6 2, 6 -2, 6 -3          3
// 2 4, 2 2, 2 -2, 2 -3     4
// 1 5, 1 -3, 1 2, 1 -2     4
// 0 7
// 0 6
// 7 6
// 4 13