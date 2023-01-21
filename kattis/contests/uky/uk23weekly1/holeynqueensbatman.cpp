#include <bits/stdc++.h>

using namespace std;

// would like to make faster
// slow

int n, m, i, cnt;
// i = r*n+c
// index i*n+j
// ldiag {0}, {n, 1}, {2n, n+1, 2}, ..., {n^2-1}
// rdiag {(n-1)*n, (n-2)*n+1, ..., n-1}
// i*n+j <-> ldiag i+j + 16
// i*n+j <-> rdiag i-j + 8
// vector<int> sol;
vector<bool> sol, diag, cols;
void dfs() {
    if (i == n) { cnt++; return; }
    for (int j = 0; j < n; j++) {
        if (cols[j] || sol[i*n+j] || diag[i+j+2*n] || diag[i-j+n]) continue;
        cols[j] = sol[i*n+j] = diag[i+j+2*n] = diag[i-j+n] = true;
        i++;
        dfs();
        i--;
        cols[j] = sol[i*n+j] = diag[i+j+2*n] = diag[i-j+n] = false;
    }
}

int main() {
    while (cin >> n >> m && n) {
        sol = vector<bool>(n*n);
        diag = vector<bool>(4*n);
        cols = vector<bool>(n);
        i = 0; cnt = 0;
        while (m--) {
            int x,y; cin >> x >> y;
            sol[x*n+y] = true;
        }
        dfs();
        cout << cnt << endl;
    }
}