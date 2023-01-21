#include <bits/stdc++.h>

using namespace std;

int inf = 1000000;
vector<vector<int>> dp;
int dfs(int n, int m) {
    if (!n) return 0;
    if (!m) return inf;
    if (m==1) return n;
    if (n==1) return 1;
    if (dp[n][m]) return dp[n][m];
    int mn = inf;
    for (int s = 1; s <= n; s++) {
        mn = min(mn, max(dfs(s-1,m-1),dfs(n-s,m)));
    }
    return dp[n][m] = mn + 1;
}

int main() {
    int n, m; cin >> n >> m;
    dp = vector<vector<int>>(n+1, vector<int>(m+1));
    int mn = dfs(n,m);
    int start = n, end = 0;
    for (int s = 1; s <= n; s++) {
        int an = max({dfs(s-1,m-1),dfs(n-s,m)}) + 1;
        if (an == mn) {
            start = min(start, s);
            end = max(end, s);
        }
    }
    if (start==end)
        cout << mn << " " << start << endl;
    else
        cout << mn << " " << start << "-" << end << endl;
}