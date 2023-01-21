#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt {
    ll x = 0, y = 0; pt(ll x, ll y) : x(x), y(y) {}
    pt operator+(const pt &p) const { return {x + p.x, y + p.y}; }
    pt operator-(const pt &p) const { return {x - p.x, y - p.y}; }
    ll cross(const pt &p) const { return x * p.y - y * p.x; }
    ll dot(const pt &p) const { return x * p.x + y * p.y; }
    ll sqrLen() const { return this->dot(*this); }
};

ll shoelace(vector<pt> v) { double a = 0;
    for (int i = 0; i < v.size(); i++)
        a += v[i].cross(v[(i + 1) % v.size()]);
    return a/2; }


int main() {
    vector<pt> pts = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
    cout << shoelace(pts);

}
