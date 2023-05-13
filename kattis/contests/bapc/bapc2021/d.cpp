#include <bits/stdc++.h>

using namespace std;

#define int long long
int n;
vector<vector<int>> dp;
vector<int> v;

int32_t main() {
    cin >> n;
    v.resize(n);
    for (auto& x: v) cin >> x;

    dp.resize(n);
    for (auto& x: dp) x.resize(n);

    int ans = numeric_limits<int>::min();
    for (int i = n-1; i >= 0; i--) {
        int mx = (i==n-1 ? 0 : numeric_limits<int>::min());
        for (int j = 1; j < n; j++) {
            if (i+j < n) mx = max(mx, dp[i+j][j]);
            dp[i][j] = v[i]+mx;
            if (i==0) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}