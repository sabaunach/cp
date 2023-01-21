#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll int_fast64_t
#define ull uint_fast64_t
#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

struct met {
    int omin;
    ull dmin;
    set<int> locs;
    met() {
        omin = 999999999;
        dmin = 999999999999999999;
    }
};
struct state {
    // k, offset, (loc), (r/c), (+/-)
    int k, o, i, j, rc, d;
    state(int k, int o, int i, int j, int rc, int d):
    k(k), o(o), i(i), j(j), rc(rc), d(d) {}
};
typedef pair<int, state> node;

bool Compare(node a, node b)
{
    return a.fi >= b.fi;
}

int main() {
    priority_queue<node, vector<node>, std::function<bool(node, node)>> pq(Compare);
    int n, k; cin >> n >> k;
    if (k == 1) return 0;
    vector<vector<bool>> vis(n, vector<bool>(n));
    // [r/c][k]: for all r/c's that k is in: [locs of k]
    map<int, map<int, met>> dat[2];
    vector<pair<int, int>> rc_d = {{0, -1}, {0, 1}, {1, -1}, {1, 1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int in; cin >> in; in--;
            dat[0][in][i].locs.insert(j);
            dat[1][in][j].locs.insert(i);
            if (in == 0) {
                vis[i][j] = true;
                for (auto[rc, d]: rc_d) {
                    pq.push({0, state(0, 0, i, j, rc, d)});
                }
            }
        }
    }

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        auto[dist, c] = curr;
        //        cout << "visit dist: " << dist << ", (" << c.i << ", " << c.j << "), k=" << c.k << endl;
        //        cout << "  rc: " << c.rc << ", d: " << c.d << endl;
        //        cout << "  offset: " << c.o << endl;
        // curloc is row (i) index if c.rc = 0 [traversing rows]
        // col (j) index if c.rc = 1 [traversing cols]
        int curloc = (c.rc ? c.j : c.i) + c.d * c.o;
        // if a better one has already found this r/c, no need to check this branch, they should all be visited
        // if (dat[c.rc][c.k + 1][curloc].omin < c.o && dat[c.rc][c.k + 1][curloc].dmin < dist) continue;
        // visit all nexts in curloc (all j's if traversing rows, all i's if traversing cols)
        for (auto nloc: dat[c.rc][c.k + 1][curloc].locs) {
            int i = curloc, j = nloc;
            if (c.rc) swap(i, j);
            //            cout << "  see: (" << i << ", " << j << ")" << endl;
            if (vis[i][j]) continue;
            // TODO: this is wrong.....
            if (c.k + 1 == k - 1) {
                cout << dist;
                return 0;
            }
            vis[i][j] = true;
            for (auto[rc, d]: rc_d)
                pq.push({dist, state(c.k + 1, 0, i, j, rc, d)});
        }
        // visit next row/col of current
        auto nextloc = dat[c.rc][c.k + 1].lower_bound(curloc);
        if (nextloc == dat[c.rc][c.k + 1].end()) continue;
        if (c.d == -1) {
            nextloc--;
        } else if (nextloc->fi == curloc) {
            nextloc++;
        }
        if (nextloc == dat[c.rc][c.k + 1].end()) continue;
        int o_delta = abs(nextloc->fi - curloc);
        //        cout << "o_delta: " << o_delta << endl;
        int new_o = abs(c.o) + o_delta;
        ull new_dist = dist - (ull)pow(c.o, 2) + (ull)pow(c.o + o_delta, 2);
        //        cout << new_dist << endl;
        // if a better one has already found this r/c, no need to continue this branch
        // if (nextloc->se.omin <= new_o && nextloc->se.dmin <= new_dist) continue;
        // otw, this branch is better
        UMIN(nextloc->se.dmin, new_dist);
        UMIN(nextloc->se.omin, new_o);
        pq.push({new_dist, state(c.k, new_o, c.i, c.j, c.rc, c.d)});
    }
    cout << -1;
}
/*vector<vector<int>> occ[2];
vector<vector<vector<int>>> loc[2];
// occ[0]: rows, occ[1]: cols
occ[0].resize(k); occ[1].resize(k);
loc[0].resize(k); loc[1].resize(k);
for (int rc = 0; rc <= 1; rc++) {
    loc[rc].resize(k);
    for (auto v: loc[rc])
        v.resize(n);
}
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        int in; cin >> in; in--;
        occ[0][in].push_back(i);
        occ[1][in].push_back(j);
        loc[0][in][i].push_back(j);
        loc[1][in][j].push_back(i);
    }
}*/


/*struct met {
    int min = numeric_limits<int>::infinity();
    set<int> locs;
};
struct state {
    // k, offset, (loc), (r/c), (+/-)
    int k, o, i, j, rc, d;
    state(int k, int o, int i, int j, int rc, int d):
    k(k), o(o), i(i), j(j), rc(rc), d(d) {}
};
typedef pair<int, state> node;

int main() {
    priority_queue<node> pq;
    int n, k; cin >> n >> k;
    vector<vector<bool>> vis(n, vector<bool>(n));
    // [r/c][k]: for all r/c's that k is in: [locs of k]
    map<int, map<int, met>> dat[2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int in; cin >> in;
            dat[0][in][i].locs.insert(j);
            dat[1][in][j].locs.insert(i);
            if (in == 1) {
                vis[i][j] = true;
                vector<pair<int, int>> rc_d = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
                for (auto[rc, d]: rc_d)
                    pq.push({0, state(2, 0, i, j, rc, d)})
            }
        }
    }

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        auto[dist, c] = curr; // c++17 based?

    }
    cout << -1;
}*/
