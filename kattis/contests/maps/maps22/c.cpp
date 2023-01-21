#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    unordered_map<int, int> inds;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = {x, i};
        inds[x] = i;
        res[i] = x;
    }
    int q; cin >> q;
    sort(v.begin(), v.end());
    unordered_map<int, int> final_pos;
    for (int i = 0; i < n; i++) {
        final_pos[v[i].first] = i;
    }
    for (int i = 0; res[final_pos[q]] != q; i++) {
        while (res[final_pos[q]] != q && res[i] != v[i].first) {

            swap(res[i], res[final_pos[res[i]]]);
        }
    }
    for (auto &x: res) cout << x << " ";

}