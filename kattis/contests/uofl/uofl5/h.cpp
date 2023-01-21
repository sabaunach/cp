#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt {
    ll x, y;
};

int orientation(pt a, pt b, pt c) {
    ll v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
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

ll area(const vector<pt>& fig) {
    ll res = 0;
    for (int i = 0; i < fig.size(); i++) {
        pt p = i ? fig[i - 1] : fig.back();
        pt q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return llabs(res);// / 2;
}

ll solve() {
    int n; cin >> n;
    vector<pt> pts(n);
    for (int i = 0; i < n && cin >> pts[i].x >> pts[i].y; i++);
    convex_hull(pts, true);
    //    cout << pts.size() << endl;
    // cout << "[";
    // for (auto pt: pts) {
    //     cout << "(" << pt.x << ", " << pt.y << "), ";
    // }
    // cout << "]\n";
    if (pts.size() <= 4) return area(pts);
    // greedily shift pts to increase area
    vector<int> ind = {0,1,2,3};
    ll a = area({pts[ind[0]], pts[ind[1]], pts[ind[2]], pts[ind[3]]});
    for (bool flag = true; flag;) {
        sort(ind.begin(), ind.end());

        flag = false;
        for (int i = 0; i <= 3; i++) {
            if ((ind[i] + 1) % pts.size() == ind[(i + 1) % 4]) continue;
            ind[i] = (ind[i] + 1) % pts.size();
            ll a_new = area({pts[ind[0]], pts[ind[1]], pts[ind[2]], pts[ind[3]]});
            if (a_new >= a) {
                a = a_new;
                flag = true;
                break;
            }
            else ind[i] = (ind[i] - 1 + pts.size()) % pts.size();
        }

        for (int i = 3; !flag && i >= 0; i--) {
            if ((ind[i] - 1 + pts.size()) % pts.size() == ind[(i - 1 + 4) % 4]) continue;
            ind[i] = (ind[i] - 1 + pts.size()) % pts.size();
            ll a_new = area({pts[ind[0]], pts[ind[1]], pts[ind[2]], pts[ind[3]]});
            if (a_new >= a) {
                a = a_new;
                flag = true;
                break;
            }
            else ind[i] = (ind[i] + 1) % pts.size();
        }
    }
    return a;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;

    while(t--) {
        ll a = solve();
        ll b = a/2;
        if(a % 2)
            cout << b << "." << "5" << endl;
        else
            cout << b << endl;
    }

    return 0;
}
