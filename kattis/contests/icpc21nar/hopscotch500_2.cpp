#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll int_fast64_t
#define ull uint_fast64_t
#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)
#define ALL(a) (a).begin(), (a).end()

int N, K;

struct met {
    bool seen[2] = {false, false};
    set<int> locs;
};

// 0: row, 1: col
// loc[r/c][k][i/j].locs = {locations of k in r/c i/j}
//                 .seen[d] = if has been seen in direction d (if all have been seen, we know a branch is done)
vector<map<int, met>> loc[2];
// occ[r/c][k] = rows/cols where k occurs
vector<vector<int>> occ[2];

// d=0 -, d=1 +
struct state {
    // k, offset, (loc), (r/c), (+/-)
    int k, o, i, j;
    bool rc, d;
    state(int k, int o, int i, int j, bool rc, bool d):
    k(k), o(o), i(i), j(j), rc(rc), d(d) {}
};
typedef pair<ull, state> node;

const int rc_d[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
bool Compare(node a, node b) { return a.fi >= b.fi; }

int32_t main() {
    cin >> N >> K;
    occ[0].resize(K); occ[1].resize(K);
    loc[0].resize(K); loc[1].resize(K);

    priority_queue<node, vector<node>, std::function<bool(node, node)>> pq(Compare);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int in; cin >> in; in--;
            occ[0][in].push_back(i);
            occ[1][in].push_back(j);
            loc[0][in][i].locs.insert(j);
            loc[1][in][j].locs.insert(i);
            if (in == 0) {
                for (auto[rc, d]: rc_d)
                    pq.push({0, state(1, 0, i, j, rc, d)});
            }
            // reachable =
        }
    }

    // state s: can reach every k in loc[rc][k][occ[rc][k][o]].locs with dist
    // open a new state for each reachable k,
    // and a state for the next rc
    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        auto[dist, s] = curr;
        auto[k, o, i, j, rc, d] = s;
        cout << endl << "visit k=" << k << ", o=" << o << ", i=" << i << ", j=" << j << ", rc=" << rc << ", d=" << d << endl;
        cout << "    dist=" << dist << endl;

        if (k == K - 1) { cout << "found: " << dist; return 0; }

        // what should o be?
        // rc 0: row, 1: col
        // if row, idx = i = index of row
        int idx = (rc ? j : i) + (d ? 1 : -1) * o;
        auto occs = occ[rc][k];

        bool fnd = binary_search(ALL(occs), idx);
        if (fnd) {
            // if row, reachable = j's in row=idx
            auto reachable = loc[rc][k][idx];

            if (reachable.seen[d]) continue;
            reachable.seen[d] = true;
            for (auto idx2: reachable.locs) {
                int i_ = idx, j_ = idx2;
                if (rc) swap(i_, j_);
                for (auto[rc_, d_]: rc_d)
                    pq.push({dist, state(k + 1, 0, i_, j_, rc_, d_)});
            }
        }

        // if row, nxt = i = index of next row
        // d=0 -, d=1 +
        auto nxt = d ? upper_bound(ALL(occs), idx) : lower_bound(ALL(occs), idx);
        // anything to do before --? if lower_bound returns end()?
        if (!d) nxt--;
        cout << "idx: " << idx << ", nxtfnd: " << *nxt << endl;
        if (nxt < occs.begin() || nxt == occs.end() || *nxt == idx) continue;

        int o_ = abs(*nxt - (rc ? j : i));
        ull dist_ = dist - (ull)pow(o, 2) + (ull)pow(o_ , 2);

        // if traversing rows, update i to nxt, if traversing cols, update j to nxt
        // int i_ = (rc ? i : *nxt), j_ = (rc ? *nxt : j);
        // cout << "  next o=" << o_ << ", i=" << i_ << ", j=" << j_ << endl;
        cout << "    dist=" << dist_ << endl;
        pq.push({dist_, state(k, o_, i, j, rc, d)});
    }
}

