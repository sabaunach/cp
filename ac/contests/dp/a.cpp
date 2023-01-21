#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n); for (auto &x: v) cin >> x;
    vector<int> c(n+2, numeric_limits<int>::max());
    c[0] = 0;
    for (int i = 0; i < n; i++) {
        c[i+1] = min(c[i+1], c[i]+abs(v[i]-v[i+1]));
        c[i+2] = min(c[i+2], c[i]+abs(v[i]-v[i+2]));
    }
    cout << c[n-1] << endl;
}