#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back

#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define sz(x) int((x).size())

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

signed main () {

    int n,m,r; cin>>n>>m>>r;

    vector<pair<int,int>> v(n);
    vector<tuple<int,int,int>> ve(m);

    for (auto &x: v) cin >> x.fi >> x.se;
    for (auto &x: ve) cin >> get<0>(x) >> get<1>(x) >> get<2>(x);

    int reg = m+1;
    rep(i,0,m) rep(j,i+1,m) {
        auto[a1,b1,c1]=ve[i];
        auto[a2,b2,c2]=ve[j];

        ll xn = b2*c1-b1*c2, xd = b1*a2-b2*a1, yn = a2*c1-a1*c2, yd = a1*b2-a2*b1;
        if (xd == 0 || yd == 0) continue;
        if ((double)xn*xn/(yd*yd) + (double)yn*yn/(xd*xd) < (double)r*r) {
            reg++;
        }
    }
    if (reg != n) { cout << "no\n"; return 0; }

    list<list<int>> s1 = {{}}, s2;
    rep(i,0,n) s1.front().push_back(i);

    rep(i,0,m) {
        auto[a,b,c] = ve[i];
        int cnt = 0;
        for (auto& s: s1) {
            list<int> up, dn;
            for (auto & j: s) {
                if (a*v[j].fi + b*v[j].se + c > 0)
                    up.push_back(j);
                else
                    dn.push_back(j);
            }
            if (up.size() && dn.size()) { cnt++; }
            s2.push_back(up); s2.push_back(dn);
        }
        swap(s1,s2);
        s2.clear();
    }
    for (auto&l: s1) if (l.size() > 1) { cout << "no\n"; return 0; }
    cout << "yes\n";
}