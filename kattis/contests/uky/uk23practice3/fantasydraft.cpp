#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<map<int, string>> prefs(n);
    for (int i = 0; i < n; i++) {
        int q; cin >> q;
        for (int j = 0; j < q; j++) {
            string s; cin >> s;
            prefs[i][j] = s;
        }
    }
    int p; cin >> p;
    map<int, string> m;
    unordered_map<string, map<int, string>::iterator> m_back;
    for (int i = 0; i < p; i++) {
        string s; cin >> s;
        m_back[s] = (m.insert({i, s}).first);
    }
    vector<vector<string>> res(n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            while (!prefs[j].empty() && !m_back.count(prefs[j].begin()->second))
                prefs[j].erase(prefs[j].begin());
            if (prefs[j].empty()) {
                res[j].push_back(m.begin()->second);
                m_back.erase(m.begin()->second);
                m.erase(m.begin());
            } else {
                res[j].push_back(prefs[j].begin()->second);
                m.erase(m_back[prefs[j].begin()->second]);
                m_back.erase(prefs[j].begin()->second);
                prefs[j].erase(prefs[j].begin());
            }
        }
    }
    for (auto &v: res) {
        for (auto &x: v) cout << x << " "; cout << endl;
    }
}