#include <bits/stdc++.h>

using namespace std;

#define long long int;

vector<set<int>> adj;
vector<int> h;
vector<int> d;

int tot = 0, trg;
void dfs1(int v) {
    tot += h[v];
    for (auto c: adj[v]) {
        adj[c].erase(v);
        dfs1(c);
    }
}

vector<vector<int>> ops;
void dfs3(int v) {
    for (auto c: adj[v]) {
        if (d[c]<0) {
            ops.push_back({v,c,-d[c]});
            dfs3(c);
        }
    }
}

int dfs2(int v) {
    int sum = h[v]-trg;
    for (auto c: adj[v]) {
        dfs2(c);
        sum += d[c];
        if (d[c]>0) ops.push_back({c,v,d[c]});
    }
    if (sum>=0) dfs3(v);
    return d[v] = sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    h.resize(n); d.resize(n); adj.resize(n);
    for (auto &x: h) cin >> x;
    for (int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        adj[u-1].insert(v-1);
        adj[v-1].insert(u-1);
    }

    dfs1(0);
    trg = tot/n;

    dfs2(0);
    cout << ops.size() << "\n";
    for (auto x: ops) cout << x[0]+1 << " " << x[1]+1 << " " << x[2] << "\n";
}