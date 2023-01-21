#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
map<int, int> prime;
vector<bool> is_prime;

void sieve(int n) {
    is_prime = vector<bool>(n+1, true);
    is_prime[0] = false;
    for (int i = 2; i*i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i*i; j<=n; j+=i) {
            is_prime[j] = false;
        }
    }
    for (int i = 1; i < n+1; i++) {
        if (is_prime[i]) {
            prime[i] = primes.size();
            primes.push_back(i);
        }
    }
}


vector<int> dp;

void solve() {
    int n; cin >> n;
    dp = vector<int>(n+1);
    for (auto p: primes) dp[p]=1;

    int t = 1;
    for (int i = 0; i < n+1; i++) {
        if (dp[i]) continue;
        dp[i] = -t++;
        
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sieve(5000000);
    int t; cin >> t;
    while (t--)
        solve();
}