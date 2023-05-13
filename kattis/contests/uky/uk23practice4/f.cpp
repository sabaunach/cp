#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n,m,a,c,s; cin >> n >> m >> a >> c >> s;

    vector<ll> v(n);
    vector<int> b(n, 1);

    ll x = s;
    for (int i = 0; i < n; i++) {
        x = ((x*a)+c) % m;
        v[i] = x;
    }

    function<void(int, int)> chk;
    chk = [&] (int l, int r) {
        if (l >= r) return;
        // cout << l << " " << r << endl;
        int m = (l+r)/2;
        for (int i = l; i < m; i++) {
            if (v[i] > v[m]) b[i] = 0;
        }
        for (int i = m; i <= r; i++) {
            if (v[i] < v[m]) b[i] = 0;
        }
        chk(l,m-1); chk(m+1,r);
    };

    chk(0, n-1);
    cout << accumulate(b.begin(), b.end(), 0) << "\n";
}