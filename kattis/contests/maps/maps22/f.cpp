#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pt {
    double x, y;
    pt() : x(0), y(0) {}
    pt(double x, double y) : x(x), y(y) {}

    pt operator-(const pt &p) const {
        return {x - p.x, y - p.y}; }

    double dot(const pt &p) const { return x*p.x+y*p.y;}
    double cross(const pt &p) const { return x*p.y-y*p.x;}
    double sqrLen() const { return this->dot(*this); }
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

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
    for (auto & i : a) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), i, include_collinear))
            st.pop_back();
        st.push_back(i);
    }

    a = st;
}

double shoelace(vector<pt>& v) {
    double a = 0;
    for (int i = 0; i < v.size(); i++)
        a += v[i].cross(v[(i + 1) % v.size()]);
    return a/2;
}


int main() {
    int n,d,g; cin >> n >> d >> g;
    vector<pt> pts(n);
    for(auto& p : pts) cin >> p.x >> p.y;

    convex_hull(pts);

    double perm = 0;
    for(int i = 0; i < n; i++)
        perm += sqrt((pts[(i+1)%n] - pts[i]).sqrLen());

    cout << setprecision(12) << abs(shoelace(pts)) + perm*d*g + d*d*g*g*M_PI << endl;
}