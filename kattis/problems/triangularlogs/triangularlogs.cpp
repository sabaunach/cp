#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back

#define all(x) bg(x), end(x)
#define sz(x) int((x).size())
#define bg(x) begin(x)

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    map<int, map<int, int>> pts;
    rep(i,0,n) {
        int x,y,h; cin >> x >> y >> h;
        pts[x][y] = h;
    }
    vector<int> v(45);
    rep(i,0,q) {
        int x1,y1,x2,y2; cin >>x1>>y1>>x2>>y2;
        int sz = 0;
        bool good = true;
        for (auto it = pts.lb(x1); good && it != pts.ub(x2); it++) {
            for (auto it2 = it->se.lb(y1); it2 != it->se.ub(y2); it2++) {
                if (sz >= 44) { good = false; break; }
                v[sz++] = it2->se;
            }
        }

        if (!good) { cout << 1 << "\n"; continue; }
        sort(v.begin(), v.begin() + sz);
        rep(c,2,sz) {
            if (v[c-2] + v[c-1] > v[c]) { good = false; break; }
        }
        if (!good) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}