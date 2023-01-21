#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int n; cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (int j = 1; j <= n; j++) cin >> dp[0][j];
    vector<int> s(n+1);
    for (int j = 1; j <= n; j++) s[j] = s[j-1]+dp[0][j];
    auto sm = [s](int i, int l) -> int {
        if (l == 0) return 0;
        return s[i+l]-s[i-1];
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++) {
            int mn = numeric_limits<int>::max();
            for (int k = 0; k < i; k++) {
                mn = min(mn, dp[k][j] + dp[i-k-1][j+k+1] + sm(j, k) + sm(j+k+1, i-k-1));
            }
            dp[i][j] = mn;
        }
    }
    cout << dp[n-1][1];
}