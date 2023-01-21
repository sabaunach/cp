#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<double> p(n); for (auto &x: p) cin >> x;
    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i+1][j+1] += dp[i][j]*p[i];
            dp[i+1][j] += dp[i][j]*(1-p[i]);
        }
    }
    cout << setprecision(12) << accumulate(dp[n].begin()+(n/2+n%2),dp[n].end(),0.0);
}