#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll M = 10000000007;

ll mod(const ll & a) {
    return (a + M) % M;
}

ll power(ll a, ll b, const ll & m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inv(const ll & a) {
    return power(a, M - 2, M);
}

int main() {
    int N;
    cin >> N;
    vector<ll> nums, partials(N + 1);
    partials[0] = 1;

    for (int i = 1; i < N + 1; i++) {
        cout << "1 1 " << i << endl;
        ll k, v;
        cin >> k >> v;

        nums.push_back(mod((v - partials[k]) * inv(partials[k - 1])));

        for (int j = i; j > 0; j--) {
            partials[j] = mod(nums.back() * partials[j - 1] + partials[j]);
        }

    }

    cout << "2";
    for (auto num: nums)
        cout << " " << num;
    cout << endl;
}