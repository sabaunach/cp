#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define UMAX(a,b) a = max(a,b)
#define all(a) a.begin(), a.end()
struct SegTree {
    const static int N = 2e5;  // limit for array size
    int n;  // array size
    vll t;

    SegTree(int _n, vi _t) : n(_n) {
        t.resize(2*n);
        rep(i,n,2*n) t[i] = _t[i-n];
    }

    void build() {
        for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
    }

    void modify(int p, ll val) {
        for (t[p += n] = val; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
    }

    ll query(int l, int r) {
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) UMAX(res, t[l++]);
            if (r&1) UMAX(res, t[--r]);
        }
        return res;
    }
};

int main() {
    int n; cin >> n;

    vector<pair<int, int>> endpoints;
    vector<int> start(n);
    map<int, int> m1, m2;
    int t_idx = 0;
    for (int i = 0; i < n; i++) {
        int a, l; cin >> a >> l;
        start[i] = a;
        if (!m1.count(a)) m1[a] = t_idx++;
        if (!m1.count(a+l)) m1[a+l] = t_idx++;
        endpoints.emplace_back(a, i);
        endpoints.emplace_back(a+l, i);
    }
    int j = 0;
    for (auto[k,v]: m1) {
        m2[k] = j++;
    }
    sort(all(endpoints));

    vector<int> v(2*n);
    SegTree st(2*n,v);
    st.build();

    vector<int> res(n);
    vector<map<int, int>::iterator> v_it(n);

    for (auto[t, idx]: endpoints) {
        if (start[idx] == t) {
            st.modify(m2[t], 1);
            cout << "a " << st.query(0, m2[t]+1) << endl;
        } else {
            st.modify(m2[start[idx]], -1);
            res[idx] = st.query(0, m2[start[idx]]+1);
        }
    }
    for (auto x: res) cout << x << "\n";
}