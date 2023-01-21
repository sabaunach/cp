#include <bits/stdc++.h>

using namespace std;

struct pt {
    int x, y;
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

int dist(pt& a, pt& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    int n; cin >> n;
    vector<pt> spies, houses;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        char c; cin >> c;
        if (c == 'S') spies.push_back({i, j});
        else if (c == 'H') houses.push_back({i, j});
    }
    convex_hull(spies, true); convex_hull(houses, true);
    int s = spies.size(), h = houses.size();
    int mind = 1e9, minh = 0;
    for (int i = 0; i < h; i++) {
        int d = dist(spies[0], houses[i]);
        if (d < mind) {
            mind = d;
            minh = i;
        }
    }
    int maxd = mind;
    int j = minh;
    for (int i = 1; i < s; i++) {
        while (dist(spies[i], houses[(j+h-1)%h]) < dist(spies[i], houses[h])) j = (j+h-1)%h;
        while (dist(spies[i], houses[j]) > dist(spies[i], houses[(j+1)%h])) j = (j+1)%h;
        int d = dist(spies[i], houses[j]);
        maxd = max(maxd, d);
    }
    cout << maxd << endl;
}