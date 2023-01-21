#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int, int> pii;
#define fi first
#define se second

int32_t main() {
    int n, w; cin >> n >> w;
    int v_max = 100000;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].fi >> v[i].se;
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n+1, vector<int>(v_max+1, w+1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= v_max-v[i].se; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j+v[i].se] = min(dp[i+1][j+v[i].se], dp[i][j]+v[i].fi);
        }
        for (int j = v_max-v[i].se+1; j <= v_max; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }
    int max_v = 0;
    for (int i = 0; i <= v_max; i++) if (dp[n][i] <= w) max_v = i;
    cout << max_v << endl;
}