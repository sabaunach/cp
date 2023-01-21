#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> st(m);
    for (int i = 0; i < m; i++) {
        cin >> st[i];
    }

    auto ps1 = vector<int>(m);
    ps1[0] = st[0];
    auto ps2 = vector<int>(m);
    ps2[0] = st[m - 1];

    for (int i = 1; i < m; i++) {
        ps1[i] = ps1[i - 1] + st[i];
        ps2[i] = ps2[i - 1] + st[m - i - 1];
    }

    unordered_set<int> ss = {0};
    for (int p: ps1) {
        ss.insert(p);
    }
    for (int p: ps2) {
        ss.insert(p);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            ss.insert(ps1[i] + ps2[j]);
        }
    }

    int q;
    while (cin >> q) {
        cout << (ss.count(q) ? "Yes" : "No") << endl;
    }
}