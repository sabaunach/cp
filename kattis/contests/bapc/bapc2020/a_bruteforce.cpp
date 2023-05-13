#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

struct state {
    int diff, t = 0;
    bitset<N> bs;
    state(int diff, bitset<N> bs) : diff(diff), bs(bs) {}
};

namespace std {
    template<>
    struct hash<state> {
        size_t operator()(const state &x) const { return hash<bitset<1000>>{}(x.bs); }
    };
}

bool operator<(const state& lhs, const state&rhs) {
    return lhs.diff < rhs.diff;
}

bool operator==(const state& lhs, const state&rhs) {
    return lhs.bs == rhs.bs;
}

int solve() {
    int n, m; cin >> n >> m;
    bitset<N> a,b; vector<int> v_a, v_b;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        a.set(x); v_a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        b.set(x); v_b.push_back(x);
    }
    int diff = 0;
    for (int i = 0; i < m; i++) {
        diff += abs(a[i] - b[i]);
    }

    priority_queue<state> pq;
    unordered_set<state> vis;
    pq.emplace(diff, a);

    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        pair<unordered_set<state>::iterator, bool> ret;
        if (!(ret = vis.insert(x)).second) {
            // assert(ret.first->t <= x.t); // heuristic property... whatever \'v'/
            continue;
        }

        if (x.bs == b) return x.t;

        // branching: could be optimized,
        //  but we would have to do bad things to our bitset
        vector<int> v_bs = {-1};
        for (int i = 0; i < 1000; i++) {
            if (x.bs.test(i)) v_bs.push_back(i);
        }
        v_bs.push_back(n);
        for (int i = 0; i < v_bs.size()-1; i++) {
            if (v_bs[i] + 2 < -1 + v_bs[i+1]) {
                auto new_bs = x.bs;
                auto new_diff = x.diff;
                if ((v_bs[i] != -1) && (v_bs[i] < n - 1)) {
                    new_bs.reset(v_bs[i]);
                    new_bs.set(v_bs[i]+1);
                    new_diff -= abs(v_bs[i] - v_b[i-1]);
                    new_diff += abs(v_bs[i] + 1 - v_b[i-1]);
                }
                if (v_bs[i+1] != n && v_bs[i+1] > 0) {
                    new_bs.reset(v_bs[i+1]);
                    new_bs.set(v_bs[i+1]-1);
                    new_diff -= abs(v_bs[i+1] - v_b[i]);
                    new_diff += abs(v_bs[i+1] - 1 - v_b[i]);
                }

                auto new_state = state(new_diff, new_bs);
                new_state.t = x.t + 1;
                pq.push(new_state);
            }
        }
    }
    return -1;
}

int main() {
    int res;
    cout << ((res = solve()) == -1 ? "impossible" : to_string(res)) << "\n";
}