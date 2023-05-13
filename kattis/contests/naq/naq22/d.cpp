#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m; cin >> n >> m;
    vector<map<int, int>> rungs(n);
    for (int i = 0; i < m; i++) {
        int a; cin >> a; a--;
        rungs[a][i] = a+1;
        rungs[a+1][i] = a;
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int r = i;
        int h = -1;
        map<int, int>::iterator it;
        while ((it = rungs[r].upper_bound(h)) != rungs[r].end()) {
            h = it->first;
            r = it->second;
        }
        res[r] = i+1;
    }

    for (auto &x: res) cout << x << "\n";
}
