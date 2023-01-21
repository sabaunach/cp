#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
struct pt {
    ll x, y; pt() {} pt(ll x, ll y) : x(x), y(y) {}
    pt operator+(const pt &p) const { return {x + p.x, y + p.y}; }
    pt operator-(const pt &p) const { return {x - p.x, y - p.y}; }
    ll cross(const pt &p) const { return x * p.y - y * p.x; }
    ll dot(const pt &p) const { return x * p.x + y * p.y; }
    ll sqrLen() const { return this->dot(*this); }
    ll cross(const pt &a, const pt &b) const { return (a - *this).cross(b - *this); }
};

typedef complex<double> dpt;
#define x() real()
#define y() imag()

int sgn(ll val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }

int orientation(pt a, pt b, pt c) { return sgn(a.cross(b,c)); }

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                   < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

struct line {
    pt p1, p2; line() {} line(const pt & p1, const pt & p2) : p1(p1), p2(p2) {}
    ll a() const { return p2.y - p1.y; }
    ll b() const { return p1.x - p2.x; }
    ll c() const { return a() * (p1.x) + b() * (p1.y); }
    double slope() const { return b() ? -a() / b() : DBL_MAX; }
    // bool cont(dpt p) const { min(p1.x, p2.x) <= p.x() && p.x() <= max(p1.x, p2.x)
    //                          && min(p1.y, p2.y) <= p.y() && p.y() <= max(p1.y, p2.y); }

    dpt inter(const line &l) {
        double deter = a() * l.b() - l.a() * b();
        if (deter != 0) {
            double x = (c() * l.b() - l.c() * b()) / deter;
            double y = (a() * l.c() - l.a() * c()) / deter;
            return dpt (x, y);
        }
        return DBL_MAX, DBL_MAX;
    }
};




int main() {
    int N, K;
    vector<pt> boundary(K);
    for (int i = 0; i < K; i++) {
        ll x, y; cin >> x >> y;
        boundary[i] = pt(x, y);
    }
    vector<pt> trees(K);
    for (int i = 0; i < K; i++) {
        ll x, y; cin >> x >> y;
        trees[i] = pt(x, y);
    }
    convex_hull(trees);

}