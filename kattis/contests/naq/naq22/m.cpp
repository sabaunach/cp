#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> v;
    vector<unordered_set<int>> ccs;
    vector<unordered_map<int, vector<int>>> qs;
    vector<int> qsi;
    vector<int> qsz;
    explicit DSU(int n) : v(n, -1), ccs(n), qs(n), qsi(n), qsz(n) {
        for (int i = 0; i < n; i++) ccs[i].insert(i);
        for (int i = 0; i < n; i++) qsi[i] = i;
    }
    int get(int x) { return v[x] < 0 ? x : v[x] = get(v[x]); }
    bool same(int x, int y) { return get(x) == get(y); }
    bool unite(int x, int y, unordered_set<int>& toProcess) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (v[x] < v[y]) swap(x, y);
        v[y] += v[x]; v[x] = y;
        unordered_set<int> toRemove;
        int xi = qsi[x], yi = qsi[y];
        if (qs[xi].size() < ccs[y].size()) {
            for (auto &[k,i]: qs[xi]) {
                if (ccs[y].count(k)) {
                    toRemove.insert(k);
                    qsz[xi]-=i.size();
                    for (auto& z: i) toProcess.insert(z);
                }
            }
        } else {
            for (auto &k: ccs[y]) {
                if (qs[xi].count(k)) {
                    toRemove.insert(k);
                    qsz[xi]-=qs[xi][k].size();
                    for (auto& z: qs[xi][k]) toProcess.insert(z);
                }
            }
        }
        for (auto& e: toRemove) qs[xi].erase(e);
        toRemove.clear();
        if (qs[yi].size() < ccs[x].size()) {
            for (auto &[k,i]: qs[yi]) {
                if (ccs[x].count(k)) {
                    toRemove.insert(k);
                    qsz[yi]-=i.size();
                    for (auto& z: i) toProcess.insert(z);
                }
            }
        } else {
            for (auto &k: ccs[x]) {
                if (qs[yi].count(k)) {
                    toRemove.insert(k);
                    qsz[yi]-=qs[yi][k].size();
                    for (auto& z: qs[yi][k]) toProcess.insert(z);
                }
            }
        }
        for (auto& e: toRemove) qs[yi].erase(e);

        for (auto &e: ccs[x]) ccs[y].insert(e);
        if (qsz[xi] < qsz[yi]) {
            qsz[yi]+=qsz[xi];
            for (auto &q: qs[xi]) for (auto &e: q.second) qs[yi][q.first].push_back(e);
            qs[xi].clear();
        } else {
            qsz[xi]+=qsz[yi];
            for (auto &q: qs[yi]) for (auto &e: q.second) qs[xi][q.first].push_back(e);
            qs[yi].clear();
            qsi[y] = qsi[x];
        }
        return true;
    }
};

int main() {
    int n,m,q; cin >> n >> m >> q;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(w, make_pair(u,v));
    }

    vector<pair<int, int>> queries;

    DSU dsu(n);
    for (int i = 0; i < q; i++) {
        int a,b; cin >> a >> b;
        a--; b--;
        queries.emplace_back(a,b);
        dsu.qs[a][b].push_back(i);
        dsu.qsz[a]++;
    }
    sort(edges.begin(), edges.end());

    vector<pair<int, int>> ans(q);
    unordered_set<int> toProcess;
    int t_last = -1;
    for (auto &e: edges) {
        if (e.first > t_last) {
            for (auto i: toProcess) {
                ans[i].first = t_last;
                ans[i].second = -dsu.v[dsu.get(queries[i].first)];
            }
            toProcess.clear();
        }
        t_last = e.first;
        dsu.unite(e.second.first, e.second.second, toProcess);
    }
    for (auto i: toProcess) {
        ans[i].first = t_last;
        ans[i].second = -dsu.v[dsu.get(queries[i].first)];
    }
    for (auto &pr: ans) cout << pr.first << " " << pr.second << "\n";
}