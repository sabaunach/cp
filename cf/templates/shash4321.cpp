#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> mat;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

template <class T>
using uset = unordered_set<T>;

template <class K, class V>
using umap = unordered_map<K,V>;

istream& operator>>(istream& is, pii& p) {
    return is >> p.first >> p.second;
}

ostream& operator<<(ostream& os, pii& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v) is >> i;
    return is;
}

template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(auto& i : v) os << i << " ";
    return os;
}

#define pub push_back
#define pob pop_back
#define fi first
#define se second
#define sz(c) (int)c.size()

#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define rep(i,s,e) for(ll i=(s)-((s)>(e)); i != (e)-((s)>(e));((s)<(e) ? i++ : i--))
#define repe(i,c) for (auto& i : (c))

#define R(x) int x; cin >> x
#define RL(x) ll x; cin >> x
#define RS(x) string x; cin >> x

#define RV(x,n) vi x(n); cin >> x
#define RVL(x,n) vll x(n); cin >> x
#define RVD(x,n) vd x(n); cin >> x

#define RN R(n)
#define RNV R(n); RV(v,n)

#define UMIN(a,b) (a) = min((a), (b))
#define UMAX(a,b) (a) = max((a), (b))
#define CHMIN(a,b) (((a) = min((a),(b))) == b)
#define CHMAX(a,b) (((a) = max((a),(b))) == b)

#define RV_(x) for(auto& i : x) cin >> i
#define RA(num, args...) int _v[num]; RV_(_v); auto&[args] = _v


#define T(args...) [args]


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

vi toBase(ll n, int b) {
    vi ans;
    while (n) {
        ans.pub(n%b);
        n /= b;
    }
    reverse(all(ans));
    return ans;
}

ll toDec(vi v, int b) {
    ll ans = 0;
    repe(i,v) ans = b*ans + i;
    return ans;
}

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
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

    long long dfs(int v, long long pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

vll primes;

void sieve(int N, vll& primes) {
    primes.clear();
    vector<bool> isp(N+1,true);
    rep(i,2,N+1) {
        if(isp[i]) {
            primes.pub(i);
            for(ll j = 1LL*i*i; j < N+1; j+=i)
                isp[j] = false;
        }
    }
}

void sieve2(int k, int N, vll& bads) {
    bads.clear();
    vector<bool> isb(N+1,false);
    rep(i,0,N+1) {
        if(!isb[i]) {
            bads.pub(i%(k+1));
            for(ll j = 1; i+j < N+1; j*=k)
                isb[i+j] = true;
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

ll inv(ll x, ll M) {
    return power(x, M-2, M);
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const pair<T1, T2> &pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

// struct pt {
//     double x, y;
// };

// int orientation(pt a, pt b, pt c) {
//     double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
//     if (v < 0) return -1; // clockwise
//     if (v > 0) return +1; // counter-clockwise
//     return 0;
// }

// bool cw(pt a, pt b, pt c, bool include_collinear) {
//     int o = orientation(a, b, c);
//     return o < 0 || (include_collinear && o == 0);
// }
// bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

// void convex_hull(vector<pt>& a, bool include_collinear = false) {
//     pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
//         return make_pair(a.y, a.x) < make_pair(b.y, b.x);
//     });
//     sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
//         int o = orientation(p0, a, b);
//         if (o == 0)
//             return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
//                 < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
//         return o < 0;
//     });
//     if (include_collinear) {
//         int i = (int)a.size()-1;
//         while (i >= 0 && collinear(p0, a[i], a.back())) i--;
//         reverse(a.begin()+i+1, a.end());
//     }

//     vector<pt> st;
//     for (int i = 0; i < (int)a.size(); i++) {
//         while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
//             st.pop_back();
//         st.push_back(a[i]);
//     }

//     a = st;
// }

void solve() {

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}