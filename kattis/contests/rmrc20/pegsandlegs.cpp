#include <bits/stdc++.h>

using namespace std;
#define double long double
#define fi first
#define se second
vector<double> l,r;
vector<int> lch, rch;
vector<int> par;
vector<double> val;
vector<double> stu;
vector<bool> vis;
double ans = 0;

pair<double, double> dfs(int x) {
    if (vis[x]) {
        if (par[x] == -1) ans = max(ans, val[x]);
        return {val[x], stu[x]};
    }
    vis[x] = true;
    auto ld = dfs(lch[x]), rd = dfs(rch[x]);
    val[x] = l[x]*ld.first+r[x]*rd.first;
    stu[x] = l[x]*ld.second+r[x]*rd.second+1-l[x]-r[x];

    if (par[x] == -1) ans = max(ans, val[x]/(1-stu[x]));
    return {val[x], stu[x]};
}

int main() {
    int L, P; cin >> L >> P;
    l.resize(L+P); r.resize(L+P);
    lch = vector<int>(L+P, -1);
    rch = vector<int>(L+P, -1);
    par = vector<int>(L+P, -1);
    val.resize(L+P); vis.resize(L+P);
    stu.resize(L+P);
    for (int i = 0; i < L; i++) {
        cin >> val[i];
        vis[i] = true;
        stu[i] = 0;
    }
    for (int i = L; i < L+P; i++) {
        cin >> l[i] >> r[i] >> lch[i] >> rch[i];
        lch[i]--; rch[i]--;
        par[lch[i]] = i; par[rch[i]] = i;
    }
    for (int i = 0; i < L+P; i++) {
        dfs(i);
    }
    cout << setprecision(12) << ans << endl;
}