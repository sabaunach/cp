/* https://vjudge.net/contest/556429#problem/A
 */
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

#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define sz(x) int((x).size())

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef vector<int> vi;

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
    if (btoa[j] == -1) return 1;
    vis[j] = 1; int di = btoa[j];
    for (int e : g[di])
        if (!vis[e] && find(e, g, btoa, vis)) {
            btoa[e] = di;
            return 1;
        }
    return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
    vi vis;
    rep(i,0,sz(g)) {
        vis.assign(sz(btoa), 0);
        for (int j : g[i])
            if (find(j, g, btoa, vis)) {
                btoa[j] = i;
                break;
            }
    }
    return sz(btoa) - (int)count(all(btoa), -1);
}

vi cover(vector<vi>& g, int n, int m) {
    vi match(m, -1);
    int res = dfsMatching(g, match);
    vector<bool> lfound(n, true), seen(m);
    for (int it : match) if (it != -1) lfound[it] = false;
    vi q, cover;
    rep(i,0,n) if (lfound[i]) q.push_back(i);
    while (!q.empty()) {
        int i = q.back(); q.pop_back();
        lfound[i] = 1;
        for (int e : g[i]) if (!seen[e] && match[e] != -1) {
                seen[e] = true;
                q.push_back(match[e]);
            }
    }
    rep(i,0,n) if (!lfound[i]) cover.push_back(i);
    rep(i,0,m) if (seen[i]) cover.push_back(n+i);
    assert(sz(cover) == res);
    return cover;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n); fore(x, v) cin >> x;

    vector<unordered_set<int>> adj(n); rep(i,0,n) rep(j,0,n) if (i != j) adj[i].insert(j);
    rep(i,0,n) rep(j,i+1,n) {
        int cnt = 0;
        rep(c,0,v[i].size()) if (v[i][c] != v[j][c]) cnt++;
        if (cnt > 2) {
            adj[i].erase(j); adj[j].erase(i);
        }
    }

    vector<vi> a; vector<int> b;
    vector<int> col(n), x(n);
    function<void(int, int)> dfs;
    dfs = [&] (int v, int c = -1) {
        if (col[v]) return; col[v] = c;
        if (c == -1) { x[v] = sz(a); a.pub({}); }
        else { x[v] = sz(b); b.pub(-1); }
        fore(u, adj[v]) {
            dfs(u, c*-1);
            if (c == -1) a[x[v]].pub(x[u]);
        }
    };
    rep(i,0,n) dfs(i, -1);

    cout << n - dfsMatching(a, b) << "\n";
}