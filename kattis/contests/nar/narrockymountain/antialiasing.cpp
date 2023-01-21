#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define fi first
#define se second

struct frac {
    int n = 0, d = 1; frac() {} frac(int n, int d) : n(n), d(d) {}
    frac simplify() { int g = gcd(n, d); n /= g, d /= g; return *this; }
    frac operator+(const frac &a) const { int l = lcm(d, a.d); return frac(n * (l / d) + a.n * (l / a.d), l).simplify(); }
    frac operator*(const frac &a) const { return frac(n * a.n, d * a.d).simplify(); }
    frac operator-(const frac &a) const { return *this + frac(-1*a.n, a.d);  }
    frac operator/(const frac &a) const { if (a.n == 0) throw runtime_error("divide by 0"); return *this * frac(a.d, a.n); }
    [[nodiscard]] double val() const { return (double)n / (double)d; }
};
bool operator<(const frac &a, const frac&b) { return (a.n * b.d) < (b.n * a.d); }
bool operator==(const frac &a, const frac&b) { return (a.n * b.d) == (b.n * a.d); }
bool operator==(const frac &a, const double&b) { return a.val() == b; }
frac abs(const frac &a) { return frac(abs(a.n), a.d); }
ostream & operator<<(ostream & s, const frac & a) { return s << (to_string(a.n) + "/" + to_string(a.d)); }

struct pt {
    frac x = {0, 0}, y = {0, 0}; pt() {} pt(frac x, frac y) : x(x), y(y) {}
    pt operator+(const pt &p) const { return {x + p.x, y + p.y}; }
    pt operator*(const pt &p) const { return {x * p.x, y * p.y}; }
    pt operator-(const pt &p) const { return {x - p.x, y - p.y}; }
    pt operator/(const pt &p) const { if (p.x == 0 || p.y == 0) throw runtime_error("divide by 0"); return {x / p.x, y / p.y}; }
    frac cross(const pt &p) const { return x * p.y - y * p.x; }
    frac dot(const pt &p) const { return x * p.x + y * p.y; }
    frac sqrLen() const { return this->dot(*this); }
};
bool operator<(const pt &a, const pt &b) { return a.x < b.x || a.y < b.y; }
bool operator==(const pt &a, const pt &b) { return a.x == b.x && a.y == b.y; }
bool operator!=(const pt &a, const pt &b) { return !(a == b); }
ostream & operator<<(ostream & s, const pt & a) { return s << "(" << a.x << ", " << a.y << ")"; }

int N, Q;
int main() {
    cin >> N >> Q;

    vector<vector<frac>> lum(1001, vector<frac>(1001));
    vector<pair<int, int>> c_bnd(1001), r_bnd(1001);
    vector<pt> pts;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        pts.emplace_back(frac(x * 2 + 1, 2), frac(y * 2 + 1, 2));
    }

    for (int i = 0; i < N; i++) {
        auto pt1 = pts[i], pt2 = pts[(i + 1) % N];
        auto rise = pt2.y - pt1.y; auto run = pt2.x - pt1.x;
        cout << "i: " << i << endl;
        cout << pt1 << " to " << pt2 << endl;
        do {
            vector<pair<frac, pt>> nxts;
            auto nx = frac((run.n > 0) ? floor(pt1.x.val() + 1) : ceil(pt1.x.val() - 1), 1),
                 ny = frac((rise.n > 0) ? floor(pt1.y.val() + 1) : ceil(pt1.y.val() - 1), 1);

            if (rise.n != 0) nxts.push_back({(ny - pt1.y) / rise, pt(pt1.x + run * ((ny - pt1.y) / rise), ny)});
            if (run.n != 0) nxts.push_back({(nx - pt1.x) / run, pt(nx, pt1.y + rise * ((nx - pt1.x) / run))});
            if (run.n != 0) nxts.push_back({(nx - pt1.x) / run, pt2});
            else nxts.push_back({(ny - pt1.y) / rise, pt2});

            sort(ALL(nxts));

            pt nxt = nxts[0].se;
            cout << "\t" << pt1 << " to " << nxt << endl;
            int x = floor(nxt.x.val()), y = floor(nxt.y.val());
            lum[x][y] = lum[x][y] + frac(1,2)*abs(nxt.x - pt1.x)*abs(nxt.y - pt1.y);

            cout << "\tlum: " << lum[x][y] << endl;
            if (nxt == pt2) break;
            lum[x][y] = lum[x][y] + ((rise.n > 0) ? abs(nxt.y - frac(y, 1)) : abs(nxt.x - frac(x, 1)));

            cout << "\tlum: " << lum[x][y] << endl;
            pt1 = nxt;
        } while (pt1 != pt2);

    }

}

