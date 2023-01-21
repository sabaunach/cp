#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int, int> pii;
#define fi first
#define se second

int32_t main() {
    int n, w; cin >> n >> w;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].fi >> v[i].se;
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n+1, vector<int>(w+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w-v[i].fi; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+v[i].fi] = max(dp[i+1][j+v[i].fi], dp[i][j]+v[i].se);
        }
        for (int j = w-v[i].fi+1; j <= w; j++) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }
    cout << *max_element(dp[n].begin(), dp[n].end());
}