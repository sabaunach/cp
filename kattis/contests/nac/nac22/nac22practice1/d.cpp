#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct DSU {
    vector<int> e; void init(int N) { e = vector<int>(N,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] < e[y]) swap(x,y);
        e[y] += e[x]; e[x] = y; return 1;
    }
};

ll N, A, B;
ll l[100000], r[100000], t[100000];

int main() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i] >> t[i];
    }

    // {{a, b}, dist}
    queue<pair<pair<ll,ll>, ll>> q;
    q.push({{A, B}, 0});
    DSU dsu; dsu.init(N);

    while (!q.empty()) {
        const auto&[ab, d] = q.front();
        const auto&[a, b] = ab;
        q.pop();
        if (t[a] != t[b]) {
            cout << d;
            return 0;
        }

        if (!dsu.unite(a, b)) continue;

        q.push({{l[a], l[b]}, d + 1});
        q.push({{r[a], r[b]}, d + 1});
    }
    cout << "indistinguishable";
}