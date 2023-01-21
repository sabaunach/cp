#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> dp;
int ans = 0;
int dfs(int v) {
    if (dp[v] != -1) return dp[v];
    int mx = 0;
    for (auto c: adj[v]) mx = max(mx, 1+dfs(c));
    ans = max(ans, mx);
    return dp[v] = mx;
}

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n);
    dp = vector<int>(n, -1);
    for (int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        adj[x-1].push_back(y-1);
    }
    for (int i = 0; i < n; i++) dfs(i);
    cout << ans << endl;
}