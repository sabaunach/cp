#include <bits/stdc++.h>

using namespace std;

//void solve() {
//    int n; cin >> n;
//    int mn = 100, mx = -1;
//    while (n--) {
//        int in; cin >> in;
//        mn = min(mn, in);
//        mx = max(mx, in);
//    }
//    cout << (mx-mn)*2 << endl;
//}

void solve() {
    int n; cin >> n;
    vector<int> v(n); for (auto& x: v) cin >> x;
    auto[mn, mx] = minmax_element(v.begin(), v.end());
    cout << (*mx-*mn)*2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}
