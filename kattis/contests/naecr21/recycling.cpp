#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct DSU {
    vector<int> e, l_, r_;
    void init(int N) {
        e = l_ = r_ = vector<int>(N,-1);
        for (int i = 0; i < N; i++) { l_[i] = i; r_[i] = i; }
    }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    int l(int x) { return l_[get(x)]; }
    int r(int x) { return r_[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        l_[x] = min(l(x), l(y));
        r_[x] = max(r(x), r(y));
        e[x] += e[y]; e[y] = x;
        return 1;
    }
};

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) pq.push({v[i], i});
    DSU dsu;
    dsu.init(n);

    ll res = 0, l = 0, r = 0;
    while (!pq.empty()) {
        auto[_, i] = pq.top(); pq.pop();
        if (i > 0 && v[i - 1] >= v[i]) {
            dsu.unite(i - 1, i);
        }
        if (i + 1 < n && v[i + 1] >= v[i]) {
            dsu.unite(i + 1, i);
        }
        ll val = (ll)dsu.size(i) * (ll)v[i];
        if (val > res || (val == res && dsu.l(i) < l)) {
            res = val;
            l = dsu.l(i);
            r = dsu.r(i);
        }
    }
    cout << l + 1 << " " << r + 1 << " " << res;
}
