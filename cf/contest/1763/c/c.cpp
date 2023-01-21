#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

#define FORE(i,a) for(auto &i : a)
#define FORIT(it,a) for(auto it = a.begin(); it != a.end();)
#define FOR_4(i,a,b,d) for(int i=(a)-((a)>(b));i!=(b)-((a)>(a));((a)<(b)?i+=d:i-=d))
#define FOR_3(i,a,b) FOR_4(i,a,b,1)
#define FOR_X(x,i,a,b,d,F,...) F
#define FOR(a...) FOR_X(,a,FOR_4(a),FOR_3(a),FOR_2(a))

#define fi first
#define se second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define sz(c) (int)c.size()

template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    FORE(i, v) is >> i;
    return is;
}

template<class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.fi >> p.se;
    return is;
}

template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
    FORE(i, v) os << i << " ";
    return os;
}

template<class T, class U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
    os << p.fi << " " << p.se;
    return os;
}


typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<double> vd;
typedef list<int> li;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<string, int> msi;

#define R(x) int x; cin >> x
#define RS(x) string x; cin >> x
#define RD(x) double x; cin >> x

#define RV_1(v) FORE(x, v) cin >> x
#define RV_2(v, n) vi v(n); RV_1(v)
#define RV_X(x, v, n, FUNC, ...) FUNC
#define RV(args...) RV_X(,args,RV_2(args),RV_1(args))

#define RNV_0() R(n); RV(v, n)
#define RNV_2(n, v) R(n); RV(v, n)
#define RNV_3(n, v1, v2) R(n); RV(v1, n); RV(v2, n)
#define RNV_X(x, n, v1, v2, FUNC, ...) FUNC
#define RNV(args...) RNV_X(,args,RNV_3(args),RNV_2(args),RNV_0(args))

#define ALL(c) begin(c), end(c)
#define RALL(c) rbegin(c), rend(c)

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

#define B(args...) [args]

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

// have to be turbo-greedy
// what's the max, and what's the min we can make on either side, propagate (max-min) if we can
// do this over all indices?
// 8 17 24 9
// 9 9 24 9
// oh it always make zero
// 4 9 5
// 4 9 5 5
// 4 9 9 9
// 5 5 9 9
// 9 9 9 9

// 1 4 1
// 3 3 1
// 3 2 2

// 1 7 1
// 6 6 1
//

// 1 5 1
// 4 4 1
// 4 3 3

// 1 2 1
// 3 2 3

// 0 7 0
// 7 7 0
// 7 7 7

// 1 7 0
// 1 7 7
// 6 6 7

// 7 1 3
// 7 2 2
// 7 0 0
// 7 7 7

// 1 8 1
// 7 7 1
// 7 6 6


// 1 8 1
// 7 7 1
//

// 0 8 1
// 8 8 1
// 8 8 8


void solve() {
    RNV();
    if (n==2) { cout << max(v[0]+v[1], 2*abs(v[0]-v[1])) << "\n"; return; }
    if (n!=3) { cout << *max_element(ALL(v))*n << "\n"; return; }
    int mx = max({
        v[0]*3, v[2]*3,
        v[0]+v[1]+v[2],
        2*abs(v[0]-v[1])+v[2],
        2*abs(v[1]-v[2])+v[0],
        abs(v[0]-v[1])+2*abs(abs(v[0]-v[1])-v[2]),
        abs(v[1]-v[2])+2*abs(abs(v[1]-v[2])-v[0]),
        abs(v[0]-v[1])*3,
        abs(v[1]-v[2])*3
    });
    cout << mx << "\n";
}

int32_t main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) solve();
}