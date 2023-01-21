#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (n==1) { cout << n << "\n" << s << "\n"; return; }

    string ans(n, '.');
    int g = 0, h = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int idx = min(i+k,n-1);
        if (g-- <= 0 && s[i] == 'G') {
            cnt++;
            if (ans[idx] == '.')
                ans[idx] = 'G';
            else
                ans[idx-1] = 'G';
            g = k*2;
        }
        if (h-- <= 0 && s[i] == 'H') {
            cnt++;
            if (ans[idx] == '.')
                ans[idx] = 'H';
            else
                ans[idx-1] = 'H';
            h = k*2;
        }
    }
    cout << cnt << "\n" << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

}