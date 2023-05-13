#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> used, st;
vector<int> order;

bool dfs(int v) {
    bool res = true;
    st[v] = used[v] = true;
    for (auto u: adj[v])
        if (!used[u])
            res &= dfs(u);
        else if (st[u])
            res = false;
    order.push_back(v);
    st[v] = false;
    return res;
}

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n); used.resize(n); st.resize(n);

    for (int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    used.assign(n, false);

    bool acyclic = true;
    for (int i = 0; i < n; i++)
        if (!used[i])
            acyclic &= dfs(i);

    if (!acyclic) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(order.begin(), order.end());

    for (auto x: order) cout << x+1 << "\n";
}