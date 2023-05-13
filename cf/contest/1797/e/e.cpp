#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using db = long double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vc = vector<char>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

template<typename C>
struct is_iterable
{
    typedef long false_type;
    typedef char true_type;
    template<class T> static false_type check(...);
    template<class T> static true_type  check(int, typename T::const_iterator = C().end());
    enum { value = sizeof(check<C>(0)) == sizeof(true_type) };
};
template <typename T, typename S>
struct is_string
{
    static const bool value = false;
};
template <class T, class Traits, class Alloc>
struct is_string<T, std::basic_string<T, Traits, Alloc>>
{
    static const bool value = true;
};

#define tcT template<class T
#define tcTU tcT, class U
#define tcTUU tcT, class ...U
#define tcitT template<class T, typename = typename enable_if<is_iterable<T>::value && !is_string<char, T>::value>::type

tcT> using v = vector<T>;
tcT, size_t SZ> using ar = array<T,SZ>;
tcTU> using pr = pair<T,U>;
tcTU> using umap = unordered_map<T,U>;
tcTU> using mmap = multimap<T,U>;
tcTU> using ummap = unordered_multimap<T,U>;
tcT> using uset = unordered_set<T>;
tcT> using mset = multiset<T>;
tcT> using umset = unordered_multiset<T>;

#define mp make_pair
#define fi first
#define se second

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front
#define bk back
#define pub push_back
#define pob pop_back
#define eb emplace_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
tcT> int lwb(v<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(v<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

tcTU> ostream& operator<<(ostream& s, pr<T, U>& p) {
    s << "{" << p.fi << ", " << p.se << "}"; return s;
}
tcitT> ostream& operator<<(ostream& s, T& ds) {
    auto it = bg(ds); s << "{";
    for (; next(it) != end(ds); it++) {
        s << *it << ", ";
    }
    if (it != end(ds)) s << *it << "}";
    return s;
}

tcTU> istream& operator>>(istream& s, pr<T, U>& p) {
    s >> p.fi >> p.se; return s;
}
tcitT> istream& operator>>(istream& s, T& ds) {
    for (auto it = bg(ds); it != end(ds); it++) {
        s >> *it;
    }
    return s;
}

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

constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x))
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cediv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fldiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
tcT> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
tcT> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

vl toBase(ll n, int b) { vl ans; while (n) { ans.pub(n%b); n /= b; }
    reverse(all(ans)); return ans; }
ll toDec(const vl& v, int b) { ll ans = 0;
    fore(i,v) ans = b*ans + i; return ans; }

tcT> void remDup(vector<T>& v) {
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcT> map<T, int> lis(vector<T>& v) {
    map<T, int> m;
    rep(i, 0, sz(v)) {
        if (auto it = m.lb(v[i]); it != m.end()) m.erase(it);
        m[v[i]] = i;
    }
    return m;
}

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}
struct Mod {
    ll v = 0;
    static const ll mod = 1e9+7;
    Mod(ll v) : v(v) {} Mod() {}
    Mod operator+(Mod b) const { return (v + b.v) % mod; }
    Mod operator-(Mod b) const { return (v - b.v + mod) % mod; }
    Mod operator*(Mod b) const { return (v * b.v) % mod; }
    Mod operator/(Mod b) const { return *this * b.inv(); }
    Mod inv() const {
        ll x, y, g = euclid(v, mod, x, y);
        assert(g == 1); return (x + mod) % mod;
    }
    Mod operator^(ll e) {
        if (!e) return 1;
        Mod r = *this ^ (e / 2); r = r * r;
        return e&1 ? *this * r : r;
    }
};

Mod operator ""_m(ull a) { return {(ll)a}; }

#define fact_sieve
//const int FACT_N = 100000; Mod fact[FACT_N];
//#define fact_sieve fact[0]=1_m; rep(i,1,FACT_N) fact[i] = fact[i-1]*i;
//Mod binom(int n, int k) { return fact[n]*(fact[k]*fact[n-k]).inv(); }

#define prime_sieve
const int PRIME_N = 5000000; vi primes; vb is_prime;
#define prime_sieve is_prime.resize(PRIME_N+1, true); is_prime[0] = is_prime[1] = false;\
rep(i,2,PRIME_N+1) if(is_prime[i]) { primes.pub(i); for(int j = i+i; j <= PRIME_N; j+=i) is_prime[j] = false; }

#define divisor_sieve
//const int DIVISOR_N = 100001; vi divisors(DIVISOR_N);
//#define divisor_sieve rep(i,1,DIVISOR_N) for(int j = i; j < DIVISOR_N; j+=i) divisors[j]++;

#define phi_sieve
vi phi;
#define phi_sieve phi.resize(PRIME_N+1); rep(i,1,PRIME_N+1) phi[i] = i;\
rep(i,2,PRIME_N+1) if(is_prime[i]) for(int j = i; j <= PRIME_N; j+=i) phi[j] -= phi[j]/i;

vector<vi> tbl;
vi depth, P;
vector<vi> treeJump(){
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i,1,d) rep(j,0,sz(P))
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}
int jmp(int nod, int steps){
    rep(i,0,sz(tbl))
        if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = jmp(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = sz(tbl); i--;) {
        int c = tbl[i][a], d = tbl[i][b];
        if (c != d) a = c, b = d;
    }
    return tbl[0][a];
}

struct Lca_Node{
    const static int inf = 1e9;
    Lca_Node*l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = 0;
    Lca_Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Lca_Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Lca_Node(v, lo, mid); r = new Lca_Node(v, mid, hi);
            val = lca(l->val, r->val);
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -1;
        if (L <= lo && hi <= R) return val;
        push();
        return lca(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = lca(l->val, r->val);
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
            val = lca(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Lca_Node(lo, mid); r = new Lca_Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

struct Sum_Node {
    const static int inf = 1e9;
    Sum_Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = 0;
    Sum_Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Sum_Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Sum_Node(v, lo, mid); r = new Sum_Node(v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
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
            val = l->val + r->val;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Sum_Node(lo, mid); r = new Sum_Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {

    int n,m; cin >>n>>m;
    P = phi;
    depth.resize(PRIME_N+1);
    rep(i,2,PRIME_N+1) depth[i] = depth[P[i]]+1;
    tbl = treeJump();

    vi v(n); cin >> v;
    auto lca_t = new Lca_Node(0, n);
    auto sum_t = new Sum_Node(0, n);
    map<int, int> mp;

    auto update = [&] (int i, int x, int h) {
//        int y = x, h = 0;
//        while (y > 1) y = phi[y], h++;
        if (h > 0) mp[i] = h; else mp.erase(i);
        lca_t->set(i, i+1, x);
        sum_t->set(i, i+1, h);
    };

    rep(i,0,n) {
        int y = v[i], h = 0;
        while (y > 1) y = phi[y], h++;
        update(i, v[i], h);
    }

    rep(i,0,n) cout << sum_t->query(i,i+1) << " "; cout << "\n";
    rep(i,0,n) cout << lca_t->query(i,i+1) << " "; cout << "\n";

    rep(i,0,m) {
        int t,l,r; cin >>t>>l>>r; l--;
        if (t == 1) {
            auto it = mp.lower_bound(l);
            while (it != mp.end() && it->fi < r) {
                auto[j,h] = *it; it++;
                update(j, phi[lca_t->query(j, j+1)], h-1);
            }
        } else {
            int y = lca_t->query(l, r), h = 0;
            while (y > 1) y = phi[y], h++;
            cout << sum_t->query(l, r) - (h-1)*(r-l) << "\n";
        }
    }
}

int32_t main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fact_sieve; prime_sieve; divisor_sieve; phi_sieve;

//    int t; cin >> t; while (t--)
        solve();
    // cout << solve() << "\n";
    // cout << (solve() ? "YES" : "NO") << "\n";
}