#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x, y;
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
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

double dist(pt& a, pt& b) {
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

int main() {
    int n; cin >> n;
    vector<pt> v(n);
    for (auto& point: v) {
        cin >> point.x >> point.y;
    }
    convex_hull(v);

    // things we can do because our polygon is convex:
    // for each point, b-search the longest chord
    n = v.size();
    for (auto point: v) v.push_back(point);

    for (int i = 0; i < n; i++) {
        int a = i+1, b = i+n-1,
        while (a < b) {
            int m = (a+b)/2;

        }
    }
//
//    // or do sliding window; greedily one of the two directions will increase
//    int i = 0, j = v.size()-1;
//    for (bool stop = false; !stop;) {
//        stop = true;
//        if (dist(v[i+1], v[j]) >= dist(v[i], v[j])) {
//            i++;
//            stop = false;
//        } else if (dist(v[i], v[j-1]) >= dist(v[i], v[j])) {
//            j--;
//            stop = false;
//        }
//    }
//    cout << setprecision(12) << dist(v[i], v[j]);
}