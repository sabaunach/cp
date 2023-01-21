#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n); for (auto &x: v) cin >> x;
    vector<int> c(n+k+1, numeric_limits<int>::max());
    c[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= k; j++)
            c[i+j] = min(c[i+j], c[i]+abs(v[i]-v[i+j]));
    cout << c[n-1] << endl;
}