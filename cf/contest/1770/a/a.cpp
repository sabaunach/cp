#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define double long double

#define fore(i,a) for(auto &i : a)
#define rep_4(i,a,b,d) for(int i=(a)-((a)>(b));i!=(b)-((a)>(a));((a)<(b)?i+=d:i-=d))
#define rep_3(i,a,b) rep_4(i,a,b,1)
#define rep_X(x,i,a,b,d,F,...) F
#define rep(a...) rep_X(,a,rep_4(a),rep_3(a),rep_2(a))

#define fi first
#define se second
#define pub push_back
#define emb emplace_back
#define puf push_front
#define emf emplace_front
#define pob pop_back
#define pof pop_front
#define sz(c) (int)c.size()

template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
    fore(i, v) os << i << " ";
    return os;
}

template<class T, class U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
    os << p.fi << " " << p.se;
    return os;
}

typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<pii> vii;
#define umap unordered_map
#define uset unordered_set
#define mmap multimap
#define mset multiset
#define ummap unordered_multimap
#define umset unordered_multiset

#define R(x) int x; cin >> x
#define RS(x) string x; cin >> x
#define RD(x) double x; cin >> x

#define RV_1(v) fore(x, v) cin >> x
#define RV_2(v, n) vi v(n); RV_1(v)
#define RV_X(x, v, n, FUNC, ...) FUNC
#define RV(args...) RV_X(,args,RV_2(args),RV_1(args))

#define RNV_0() R(n); RV(v, n)
#define RNV_2(n, v) R(n); RV(v, n)
#define RNV_3(n, v1, v2) R(n); RV(v1, n); RV(v2, n)
#define RNV_X(x, n, v1, v2, FUNC, ...) FUNC
#define RNV(args...) RNV_X(,args,RNV_3(args),RNV_2(args),RNV_0(args))

#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

#define B(args...) [args]

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vi> adj;
    int n, m = 0;
    int s, t;
    vi level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, ll cap) {
        edges.emb(v, u, cap);
        edges.emb(u, v, 0);
        adj[v].pub(m);
        adj[u].pub(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            auto tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (auto pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

struct SegTree {
    const static int N = 2e5;  // limit for array size
    int n;  // array size
    vll t;

    SegTree(int _n, const vi& _t) : n(_n) {
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

struct DSU {
    vi v; explicit DSU(int n) : v(n, -1) {}
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

void sieve(int N, vi& primes) {
    primes.clear();
    vb isp(N+1,true);
    rep(i,2,N+1) {
        if(isp[i]) {
            primes.pub(i);
            for(ll j = 1LL*i*i; j < N+1; j+=i)
                isp[j] = false;
        }
    }
}

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;

    while (y) {
        if (y & 1) res = (res * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return res;
}

vi toBase(ll n, int b) {
    vi ans;
    while (n) {
        ans.pub(n%b);
        n /= b;
    }
    reverse(all(ans));
    return ans;
}

ll toDec(const vi& v, int b) {
    ll ans = 0;
    fore(i,v) ans = b*ans + i;
    return ans;
}

template<typename T>
T b_search(T l, T r, const function<bool(T)>& f) {
    while (l < r) {
        T m = l+(r-l)/2;
        if (f(m))
            r = m;
        else
            l = m+1;
    }
    return l;
}

template <typename T>
T find_first_false(T l, T r, const function<bool(T)>& f) {
    if (l > r) return r + 1;
    ++r;
    T w = T(1) << __lg(r - l);
    --l;
    if (f(l + w)) l = r - w;
    for (w >>= 1; w >= T(1); w >>= 1)
        if (f(l + w)) l += w;
    return l + 1;
}

void solve() {
    R(n); R(m);
    vi a(n), b(m);
    RV(a); RV(b);

    priority_queue<int, vi, greater<>> pq;
    for (auto x: a) pq.push(x);
    for (int i = 0; i < m; i++) {
        pq.pop();
        pq.push(b[i]);
    }
    int sum = 0;
    while (!pq.empty()) { sum += pq.top(); pq.pop(); }
    cout << sum << endl;
}

int32_t main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) solve();
}