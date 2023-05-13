#include <bits/stdc++.h>

using namespace std;

// cut the piece that has the largest area?
// pq ? 200 points so can update all
// so n^3
// area -> shoelace, need to bsearch interpt?
typedef pair<double, double> pt;
#define fi first
#define se second

double cross(const pt &a, const pt& b) {
    return a.fi * b.se - a.se * b.fi;
}

double m(const pt &a, const pt &b) {
    return (a.se - b.se)/(a.fi - b.fi);
}

double inter_x(const pt&a, const pt&b, const pt&c, const pt&d) {
    return (a.se - a.fi - c.se + c.fi)/(m(c,d)-m(a,b));
}

double shoelace(vector<pt> v) {
    double a = 0;
    for (int i = 0; i < v.size(); i++)
        a += cross(v[i], v[(i + 1) % v.size()]);
    return a/2;
}

int main() {
    int A; cin >> A;
    vector<pt> a(A);
    for (int i = 0; i < A; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    int B; cin >> B;
    vector<pt> b(B);
    for (int i = 0; i < B; i++) {
        cin >> b[i].fi >> b[i].se;
    }

}
