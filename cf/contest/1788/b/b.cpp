#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
#define tcTUU tcT, class ...U
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
tcT> using PR = pair<T,T>;

#define mp make_pair
#define fi first
#define ss second

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }


#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

tcT> ostream& operator<<(ostream& s, vector<T>& v) {
    each(i, v) s << i << " "; return s;
}

tcTU> ostream& operator<<(ostream& s, pair<T, U>& p) {
    s << p.fi << " " << p.se; return s;
}

tcT> istream& operator>>(istream& s, vector<T>& v) {
    each(i, v) s >> i; return s;
}

tcTU> istream& operator>>(istream& s, pair<T, U>& p) {
    s >> p.fi >> p.se; return s;
}

constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x))
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

#define umap unordered_map
#define uset unordered_set
#define mmap multimap
#define mset multiset
#define ummap unordered_multimap
#define umset unordered_multiset

ll cediv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fldiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
tcT> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
tcT> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
    hi ++; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); // assuming f is decreasing
    while (lo < hi) { // find first index such that f is true
        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    }
    return lo;
}

tcT> void remDup(vector<T>& v) { // sort and remove duplicates
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } // element that doesn't exist from (multi)set

tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

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
        edges.eb(v, u, cap);
        edges.eb(u, v, 0);
        adj[v].pb(m);
        adj[u].pb(m + 1);
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
    vl t;

    SegTree(int _n, const vl& _t) : n(_n) {
        t.resize(2*n);
        FOR(i,n,2*n) t[i] = _t[i-n];
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
            if (l&1) ckmax(res, t[l++]);
            if (r&1) ckmax(res, t[--r]);
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
    FOR(i,2,N+1) {
        if(isp[i]) {
            primes.pb(i);
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
        ans.pb(n%b);
        n /= b;
    }
    reverse(all(ans));
    return ans;
}

ll toDec(const vi& v, int b) {
    ll ans = 0;
    each(i,v) ans = b*ans + i;
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

int N, Q, T = 1;
int sdig(int a) {
    int s = 0;
    while (a) { s+=a%10; a/=10; }
    return s;
}

void solve() {
    int x=0, y=0;
    cin >> N;
    for (int d = 1; N; N/=10, d*=10) {
        x+=fldiv(N%10,2)*d;
        y+=cediv(N%10,2)*d;
        if (N%2)
            swap(x,y);
    }
    cout << x << " " << y << endl;
}

int32_t main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) solve();
}