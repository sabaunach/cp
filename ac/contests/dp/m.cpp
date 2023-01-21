#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {

    int mod = 1000000007;
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<vector<int>> dp(n+1, vector<int>(k+2));
    vector<vector<int>> sum(n+1, vector<int>(k+2));
    vector<int> most(n+1);
    for (int j = 0; j <= v[1]; j++) dp[1][j] = 1;
    for (int j = 0; j <= v[1]; j++) sum[1][j] = ((j>0?sum[1][j-1]:0)+dp[1][j]) % mod;
    for (int i = 1; i <= n; i++) most[i] = min(most[i-1]+v[i],k);
    most[0] = k;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= most[i]; j++) {
            dp[i][j] = (sum[i-1][min(most[i-1], j)]-(j<=v[i]?0:sum[i-1][j-v[i]-1])+mod) % mod;
            sum[i][j] = ((j>0?sum[i][j-1]:0)+dp[i][j]) % mod;
        }
    }
    cout << dp[n][k] % mod << endl;
}