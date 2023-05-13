#include <bits/stdc++.h>

using namespace std;


struct DSU {
        vector<int> v; explicit DSU(int n) : v(n, -1) {}
        int get(int x) { return v[x] < 0 ? x : v[x] = get(v[x]); }
        bool same(int x, int y) { return get(x) == get(y); }
        bool unite(int x, int y) {
            x = get(x), y = get(y);
            if (x == y) return false;
            if (v[x] < v[y]) swap(x, y);
            v[y] += v[x]; v[x] = y;
            return true;
        }
};

int main() {
    int n; cin >> n;
    vector<double> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    DSU dsu(n);
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pq.push({hypot((x[i]-x[j]),(y[i]-y[j]))-r[i]-r[j], {i,j}});
        }
    }

    double c = 0;
    while (!pq.empty()) {
        auto[d, pts]= pq.top(); pq.pop();
        auto[i,j] = pts;
        if (dsu.unite(i,j)) {
            c += d;
            if (dsu.v[dsu.get(i)] == -n) break;
        }
    }
    cout << setprecision(12) << c << endl;
}