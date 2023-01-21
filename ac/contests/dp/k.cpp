#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n); for (auto &x: v) cin >> x;
    vector<int> dp(2*(k+1));
    for (int i = 0; i <= k; i++) {
        if (!dp[i]) {
            dp[i] = 1;
            for (auto j: v)
                if (!dp[i+j])
                    dp[i+j] = -1;
        }
    }
    cout << (dp[k] < 0 ? "First" : "Second") << endl;
}