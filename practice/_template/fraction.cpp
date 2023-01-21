#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct frac {
    ll n = 1, d = 1;
    frac(ll n, ll d) : n(n), d(d) {}
    frac simplify() { ll g = gcd(n, d); n /= g, d /= g;
        if (n == 0 && d != 0) d = 1;
        if (n != 0 && d == 0) n = 1;
        if (d < 0) { n = -n; d = -d; }
        return *this; }
    frac operator+(const frac &a) const {
        ll l = lcm(d, a.d); return frac(n * (l / d)
            + a.n * (l / a.d),l).simplify(); }
    frac operator*(const frac &a) const { return
        frac(n * a.n, d * a.d).simplify(); }
    frac operator-(const frac &a) const { return
        *this + frac(-1 * a.n, a.d); }
    frac operator/(const frac &a) const {
        if (a.n == 0) throw runtime_error("div by 0");
        return *this * frac(a.d, a.n); }
    [[nodiscard]] double val() const {
        return (double) n / (double) d; }
    bool operator<(const frac &a) {
        return a.n * d < n * a.d; }
    bool operator==(const frac &a) {
        return a.n * d == n * a.d; }
};
ostream &operator<<(ostream &s, const frac &a) { return
    s << (to_string(a.n) + "/" + to_string(a.d)); }

struct pt {
    frac x = {0, 0}, y = {0, 0};
    pt(frac x, frac y) : x(x), y(y) {}
    pt operator+(const pt &p) const {
        return {x + p.x, y + p.y}; }
    pt operator*(const frac &a) const {
        return pt({x * a, y * a}) ; }
    pt operator-(const pt &p) const {
        return {x - p.x, y - p.y}; }
    pt operator/(const pt &p) const {
        if (p.x.n == 0 || p.y.n == 0)
            throw runtime_error("div by 0");
        return {x / p.x, y / p.y}; }
    frac cross(const pt &p) const {
        return x * p.y - y * p.x; }
    frac dot(const pt &p) const {
        return x * p.x + y * p.y; }
    frac sqrLen() const { return this->dot(*this); }
};
