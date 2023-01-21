#include <bits/stdc++.h>

using namespace std;

#define int long long

// given a truth table determine if truth table is consistent with some program
// of form if else ifs
// must pick a var at each step with has all 1 or all 0 on its outputs of one kind
// up to 100 different inputs
// does it matter which we pick to remove?
// can there be two which are removable? yes
// does it matter? don't think so
// if it does would need dfs

// remove multiple at once?
//

//

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<vector<bool>, bool>> tables(m);
    for (int i = 0; i < m; i++) {
        char c;
        for (int j = 0; j < n; j++) {
            cin >> c;
            tables[i].first.push_back(c == '1');
        }
        cin >> c; tables[i].second = (c == '1');
    }

    map<pair<bool, bool>, int> st_map = {
            {{0,0}, 0},
            {{0,1}, 1},
            {{1,0}, 2},
            {{1,1}, 3}
    };

    vector<vector<set<int>>> v(n, vector<set<int>>(4));
    vector<bool> used_v(n), used_t(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v[j][st_map[{tables[i].first[j], tables[i].second}]].insert(i);
        }
    }

    vector<vector<int>> tr = {{0,1},{1,0},{2,3},{3,2}};
    while (true) {
        bool found = false, done = true;
        for (int i = 0; i < n; i++) {
            if (used_v[i]) continue;
            if (v[i][0].size() || v[i][1].size() || v[i][2].size() || v[i][3].size())
                done = false;
            int good = -1;
            for (auto& t: tr) {
                if (!v[i][t[0]].empty() && v[i][t[1]].empty()) {
                    good = t[0]; break;
                }
            }
            if (good == -1) continue;
            found = true;
            for (auto t: v[i][good]) {
                for (int j = 0; j < n; j++) {
                    if (j == i) continue;
                    v[j][st_map[{tables[t].first[j], tables[t].second}]].erase(t);
                }
            }
            v[i][good].clear();
        }
        if (done) { cout << "OK\n"; return; }
        if (!found) { cout << "LIE\n"; return; }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

}