#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, res; cin >> s;
    res.resize(s.size());
    int n = sqrt(s.size());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i*n + j] = s[(n-i-1) + (j)*n];
        }
    }
    cout << res << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}
