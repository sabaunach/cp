#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> v(3, vector<int>(n+1));
    for (int i = 1; i <= n; i++) cin >> v[0][i] >> v[1][i] >> v[2][i];
    vector<vector<int>> p(3, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
        p[0][i+1] = v[0][i+1]+max(p[1][i],p[2][i]);
        p[1][i+1] = v[1][i+1]+max(p[0][i],p[2][i]);
        p[2][i+1] = v[2][i+1]+max(p[0][i],p[1][i]);
    }
    cout << max({p[0][n], p[1][n], p[2][n]}) << endl;
}