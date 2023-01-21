#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int, int> pii;
#define fi first
#define se second

// bottom-up: start with segments of length 1 and build up
// as we build up, keep track of which we remove (left or right) for optimal play
int32_t main() {
    int n; cin >> n;
    vector<vector<pii>> dp(n+1, vector<pii>(n+2));
    vector<int> v(n+2); for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j].fi = dp[i-1][j-1].fi + ((n-i) % 2 ? -1 : 1)*v[j];
            dp[i][j].se = dp[i-1][j+1].se + ((n-i) % 2 ? -1 : 1)*v[j];
        }
        // optimal decision
        for (int j = 1; j <= n-i+1; j++) {
            if ((n-i) % 2) {
                dp[i][j].se = dp[i][j+i-1].fi = min(dp[i][j].se, dp[i][j+i-1].fi);
            } else {
                dp[i][j].se = dp[i][j+i-1].fi = max(dp[i][j].se, dp[i][j+i-1].fi);
            }
        }
    }
    cout << max(dp[n][1].se, dp[n][n].fi) << endl;
}