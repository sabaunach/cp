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
tcTU> using PR = pair<T,U>;
tcTU> using UMAP = unordered_map<T,U>;
tcTU> using MMAP = multimap<T,U>;
tcTU> using UUMAP = unordered_multimap<T,U>;
tcT> using USET = unordered_set<T>;
tcT> using MSET = multiset<T>;
tcT> using UMSET = unordered_multiset<T>;

#define mp make_pair
#define fi first
#define se second

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front
#define bk back
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

tcT> ostream& operator<<(ostream& s, V<T>& v) {
    each(i, v) s << i << " "; return s;
}

tcTU> ostream& operator<<(ostream& s, PR<T, U>& p) {
    s << p.fi << " " << p.se; return s;
}

tcT> istream& operator>>(istream& s, V<T>& v) {
    each(i, v) s >> i >> " "; return s;
}

tcTU> istream& operator>>(istream& s, PR<T, U>& p) {
    s >> p.fi >> " " >> p.se; return s;
}

constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x))
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

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

tcT> void re(T& t) { cin >> t; }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        FOR(L,0,31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

struct Node {
    const static int inf = 1e9;
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
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

namespace mth {
    int SIEVE = 1e5; ll MOD = 1e9+7;
    vl factorial;
    vi primes; vb is_prime;

    void factorial_sieve(int n = SIEVE, ll m = MOD) {
        factorial.resize(n);
        for (ll i = 1; i <= SIEVE; i++) {
            factorial[i] = factorial[i - 1] * i % m;
        }
    }

    void prime_sieve(int n = SIEVE) {
        primes.clear(); is_prime = vb(n+1, true);
        FOR(i,2,n+1) {
            if(is_prime[i]) {
                primes.pb(i);
                for(int j = i*i; j < n+1; j+=i)
                    is_prime[j] = false;
            }
        }
    }

    ll pow(ll x, ll y, ll m = MOD) {
        ll res = 1;
        x %= m;
        while (y) {
            if (y & 1) res = (res * x) % m;
            x = (x * x) % m;
            y >>= 1;
        }
        return res;
    }

    ll inv(ll i, ll m = MOD) {
        return i <= 1 ? i : m - (ll)(m/i) * inv(m % i) % m;
    };

    ll binomial_coefficient(int n, int k, ll m = MOD) {
        return factorial[n] * inv(factorial[k] * factorial[n-k] % m) % m;
    };

    vl toBase(ll n, int b) {
        vl ans;
        while (n) {
            ans.pb(n%b);
            n /= b;
        }
        reverse(all(ans));
        return ans;
    }

    ll toDec(const vl& v, int b) {
        ll ans = 0;
        each(i,v) ans = b*ans + i;
        return ans;
    }
};

/*
 * 1 1 5 5 5
 * 1 1 1 2 3
 *
 * 1 1 3 3 5 5
 * 1 1 1 2
 *
 * either (everything prev * cur)/(d+1) is bigger, or
 * cur is bigger (*)
 * (if cur is eq, size is everything prev + ? )
 * (but if we were to add another number,...)
 * so tracking min seq with max product, max seq with max product?
 * but as soon as we see another number, the min should be better
 * soo we only care about (*)
 *
 * if num >= what we'd add in denom, append to current sol
 * unless num > our actual sol, in which case it becomes num (i.e. if v[i] > p*v[i]/(denom*(d+1))
 * 1 > p/(denom*(d+1))
 * denom*(d+1) > p
 * otherwise, replace smallest from cur sol
 * 5 5 5 5 5 5 6
 * 1 2 3 4 5 5 5
 *
 *
 * if num >= what we'd add into denom, append to current sol
 * best we can do is (largest nums)/(smallest nums)
 *
 *
 */



// sol for general, non-decreasing sequence:
// keep a segtree, initialized to 0
// initialize n-1=1 when we read i=0, n-2=1 when we read i=1,...
/*
 *
 * 1
 * 10
 * 100
 * 100
 * 100
 *
 * either remove smallest one & add this one,
 * or append?
 *
 * whichever is bigger?
 *
 */
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (auto&x: v) cin >> x;
    int d = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {



        if (v[i] > i) {
            if (p<n && denom*(d+1) > p) {
                p = v[i];
                denom = 1;
                d = 1;
            } else {
                d++;
                denom *= d;
                if (p<n) p *= v[i];
            }
        }
        cout << d << " ";
    }
    cout << "\n";
}

int32_t main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) solve();
}