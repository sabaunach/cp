#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct frac {
    ll n = 1, d = 1;
    frac(ll n, ll d) : n(n), d(d) {}
    frac simplify() { ll g = gcd(n, d); if (g == 0) return *this = frac(0,0);
        n /= g; d /= g;
        if (n == 0 && d != 0) d = 1; if (n != 0 && d == 0) n = 1;
        if (d < 0) { n = -n; d = -d; }
        return *this; }
    frac operator+(const frac &a) const {
        return frac(n * a.d + a.n * d,a.d*d).simplify(); }
    frac operator*(const frac &a) const { return
                frac(n * a.n, d * a.d).simplify(); }
    frac operator-(const frac &a) const  { return *this + frac(-1 * a.n, a.d); }
    frac operator/(const frac &a) const { if (a.n == 0) return frac(1,0);
        return *this * frac(a.d, a.n); }
    [[nodiscard]] double val() const {
        return d == 0 ? numeric_limits<double>::infinity() : (double) n / (double) d; }
    bool operator==(const frac &a) const {
        return n * a.d == a.n * d; }
    bool operator>(const frac &a) {
        return n * a.d > a.n * d; }
};
ostream &operator<<(ostream &s, const frac &a) { return
            s << (to_string(a.n) + "/" + to_string(a.d)); }

struct pt {
    frac x = {0, 0}, y = {0, 0};
    pt(frac x, frac y) : x(x), y(y) {}
    bool operator==(const pt &p) const {return x==p.x && y==p.y;}
    pt operator+(const pt &p) const { return {x + p.x, y + p.y}; }
    pt operator*(const frac &a) const { return pt({x * a, y * a}) ; }
    pt operator-(const pt &p) const { return {x - p.x, y - p.y}; }
    bool operator>(const pt &p) { return (x == p.x) ? y > p.y : x > p.x; }
};

#undef INFINITY
frac INFINITY = frac(1,0);

struct line {
    pt p, d; line(const pt &p1, const pt &p2) : p(p1), d(p2 - p1) {}
    frac slope() const { return d.x.val() == 0 ? INFINITY : d.y/d.x; }
    frac y_int() const { return d.x.val() == 0 ? INFINITY : (p.y-p.x*slope()).simplify(); }
};

int main() {
    int n; cin >> n;
    vector<line> lines;
    unordered_map<double, vector<line>> slope_lines;
    unordered_map<double, unordered_map<double, int>> bisect_cnt;
    for (int i = 0, a, b, c, d; i < n; i++) {
        cin >> a >> b >> c >> d;
        frac f1(a,1), f2(b,1), f3(c,1), f4(d,1);
        pt p1(f1,f2), p2(f3,f4);
        if (p1 > p2) swap(p1, p2);
        auto l = line(p1,p2);
        lines.push_back(l);

        auto s1 = l.slope(),
             s2 = (s1.n == 0 ? INFINITY : frac(-1,1)/s1).simplify();
        frac b1 = l.y_int();
        slope_lines[s1.val()].push_back(l);
        auto slope = frac(s1.n + s2.n, s1.d + s2.d).simplify(),
             slope2 = slope.n == 0 ? INFINITY : frac(-1,1)/slope;
        for (auto l2: slope_lines[s2.val()]) {
            frac b2 = l2.y_int();

            frac x_loc = b1 == INFINITY ? l.p.x : (b2 == INFINITY ? l2.p.x : (b2-b1)/(s1-s2));
            frac y_loc = b1 == INFINITY ? l2.p.y : (b2 == INFINITY ? l.p.y : s1*x_loc + b1);
            pt inter = pt(x_loc, y_loc);
            frac y_inter = inter.y - inter.x * slope;
            bisect_cnt[slope.val()][y_inter.val()]++;

            frac y_inter2 = slope2 == INFINITY ? inter.x : inter.y - inter.x * slope2;
            bisect_cnt[slope2.val()][y_inter2.val()]++;
        }
    }

    long long tot = 0;
    for (auto[s,m]: bisect_cnt) {
        for (auto[_,cnt] : m) {
            tot += (cnt)*(cnt - 1)/2;
        }
    }
    cout << tot/2 << endl;
}