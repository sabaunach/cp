#include <bits/stdc++.h>

using namespace std;

vector<unordered_set<int>> adj;
vector<int> order, seen;

// dfs: path down with an even jumps, up using odd jumps
void dfs2(int v);

void dfs1(int v) {
    if (seen[v]++) return;
    order.push_back(v);
    for (auto u: adj[v])
        dfs2(u);
}

void dfs2(int v) {
    if (seen[v]++) return;
    for (auto u: adj[v])
        dfs1(u);
    order.push_back(v);
}


int main() {
    int n,m; cin >> n >> m;
    adj.resize(n); seen.resize(n);
    for (int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        x--, y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    dfs1(0);
    for (auto x: order) cout << x+1 << " "; cout << "\n";
}