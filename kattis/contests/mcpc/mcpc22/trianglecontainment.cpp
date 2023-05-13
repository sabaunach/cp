#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

struct Angle {
    int x,y; int t;
    Angle(int x, int y, int t=0) : x(x), y(y), t(t) {}
    int half() const {
        assert(x || y);
        return y < 0 || (y == 0 && x < 0);
    }
};
bool operator<(Angle a, Angle b) {
    return make_tuple(a.t, a.half(), a.y * b.x) < 
    make_tuple(b.t, b.half(), a.x * b.y);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,X; cin >> n >> X;

    vector<int> x(n), y(n);
    vector<ll> v(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> v[i];
    }

    vector<pair<Angle, int>> ang_a, ang_b;

    for (int i = 0; i < n; i++) {
        ang_a.emplace_back(Angle(x[i], y[i]), i);
        ang_b.emplace_back(Angle(x[i]-X, y[i]), i);
    }
    
    sort(all(ang_a));
    reverse(all(ang_a));
    sort(all(ang_b));
    Tree sgt(n);
    vi idx_b(n);
    rep(i,0,n) {
        idx_b[ang_b[i].second] = i;
        sgt.update(i, v[ang_b[i].second]);
    }

    vector<ll> ans(n);
    rep(i,0,n) {
        int idx = ang_a[i].second;
        int l = idx_b[idx];
        sgt.update(idx_b[idx], 0);
        ans[idx] = sgt.query(l, n);
    }


    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}