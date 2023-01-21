#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define x real()
#define y imag()
typedef complex<double> pt;
bool operator >(const pt& a, const pt& b) {
    return real(a) != real(b) ? real(a) > real(b) : imag(a) > imag(b); }
double cross(pt a, pt b) {
    return a.x*b.y - a.y*b.x;
}

struct line {
    pt p, d; line() {} line(const pt &p1, const pt &p2)
            : p(p1), d(p2 - p1) {}
    double slope() const { return d.x == 0 ? INFINITY : d.y/d.x; }
    double inter_t(const line &l) const {
        if (cross(d, l.d) == 0) return INFINITY;
        return cross(l.p-p, l.d) / cross(d, l.d); }
    pt inter(const line &l) { double t = inter_t(l);
        if (t==INFINITY) return pt(INFINITY, INFINITY);
        return pt(p.x+d.x*t, p.y+d.y*t); }
};

int main() {
    int n; cin >> n;
    vector<line> lines;
    map<double, int> slope_cnt;
    map<double, map<double, int>> bisect_cnt;
    for (int i = 0, a, b, c, d; i < n; i++) {
        cin >> a >> b >> c >> d;
        pt p1(a,b), p2(c,d);
        if (p1 > p2) swap(p1, p2);
        lines.emplace_back(p1,p2);

        auto s1 = lines[i].slope();
        for (int j = 0; j < i; j++) {
            auto s2 = lines[j].slope();
            if ((s1 == INFINITY && s2 == 0) || (s2 == INFINITY && s1 == 0) || s1 * s2 == -1) {
                double slope = (s1 == INFINITY || s2 == INFINITY) ? 1 : s1 + s2;
                pt inter = lines[i].inter(lines[j]);
                double y_inter = inter.y - inter.x * slope;
                bisect_cnt[slope][y_inter]++;

                double slope2 = slope == 0 ? INFINITY : -1/slope;
                double y_inter2 = slope2 == INFINITY ? inter.x : inter.y - inter.x * slope2;
                bisect_cnt[slope2][y_inter2]++;
            }
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