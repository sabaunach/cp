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
//const int PRIME_N = 100001; vi primes; vb is_prime(PRIME_N, true);
//#define prime_sieve rep(i,2,PRIME_N) if(is_prime[i]) {primes.pub(i); for(int j = i*i; j < PRIME_N; j+=i) is_prime[j] = false; }

void solve() {
    ll n,m; cin >>n>>m;
    cout << "? 1 1\n" << flush;
    ll d1; cin>>d1;
    ll x = 1, y = d1 + 1;
    if (n > m) swap(x, y);
    cout << "? " << x << " " << y << "\n" << flush;
    ll d2; cin>>d2;
    if (d1 == d2) {
        swap(x, y);
        cout << "? " << x << " " << y << "\n" << flush;
        if (n > m) cin >> x, x++; else cin >> y, y++;
        cout << "! " << x << " " << y << "\n" << flush;
    } else {
        if (n > m) y = d2 + 1; else x = d2 + 1;
        cout << "! " << x << " " << y << "\n" << flush;
    }

}

int32_t main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fact_sieve; prime_sieve;

    int t; cin >> t; while (t--)
    solve();
    // cout << solve() << "\n";
    // cout << (solve() ? "YES" : "NO") << "\n";
}