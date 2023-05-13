#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

struct edge {
    int d,t,a;
};

int rep(int n, int a, int c) {
    return (n*360+a)*2 + c;
}

tuple<int, int, int> bk(int st) {
    return {st/720, (st/2)%360, st%2};
}

int main() {
    int n, d, a1, a2; cin >> n >> d >> a1 >> a2;
    d--;
    auto chk = [&] (int a_enter, int a_exit) {
        auto th = ((a_exit - a_enter) + 360) % 360;
        return th <= a1 || 360 - th <= a2;
    };

    vector<vector<edge>> adj(n);
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        while (m--) {
            edge e;
            cin >> e.d >> e.t >> e.a;
            e.d--;
            adj[i].push_back(e);
        }
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, rep(0, 0, 0)});
    unordered_set<int> vis;

    while (!pq.empty()) {
        auto[cur_t, v] = pq.top(); pq.pop();
        vis.insert(v);


        auto[cur_d, a, c] = bk(v);

        // cout << cur_d << " " << a << " " << c << endl;

        if (cur_d==0 && c) {
            cout << -cur_t << "\n";
            return 0;
        }

        for (auto e: adj[cur_d]) {
            // cout << "\t" << a << " " << e.a << " " << chk(a, e.a) << " " << e.d << endl;
            if (cur_d != 0 && !chk(a, e.a)) continue;

            int ang = -1;
            for (auto e2: adj[e.d]) {
                if (e2.d == cur_d)
                    ang = (180+e2.a)%360;
            }
            // cout << "\t\t" << vis.count(rep(e.d, ang, c || e.d == d)) << "\n";
            if (vis.count(rep(e.d, ang, c || e.d == d))) continue;

            pq.push({cur_t - e.t, rep(e.d, ang, c || e.d == d)});
        }
    }

    cout << "impossible\n";
}