#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define pub push_back

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int r,c;
vector<string> b;
vector<vector<int>> adj;
vector<bool> is_land, is_sight;

vector<unordered_set<int>> component;
vector<bool> vis; unordered_set<int> seen;
bool dfs1(int x) {
    if (seen.count(x)) {
        component[x].insert(x); return true;
    }
    if (vis[x]) return false;
    vis[x] = true;
    seen.insert(x);
    fore(y, adj[x]) if (dfs1(y)) {
        swap(component[x], component[y]);
        component[x].insert(x);
        seen.erase(x); return true;
    }
    component[x].insert(x);
    seen.erase(x); return false;
}

unordered_map<int, int> freq;
void d(int i, int d) {
    if (i==r*c) return;
    int x=i/c, y=i%c;
    if (x>0 && is_sight[i-c]) { if ((freq[i-c]+=d) == 0) freq.erase(i-c); }
    if (x+1<r && is_sight[i+c]) { if ((freq[i+c]+=d) == 0) freq.erase(i+c); }
    if (y>0 && is_sight[i-1]) { if ((freq[i-1]+=d) == 0) freq.erase(i-1); }
    if (y+1<c && is_sight[i+1]) { if ((freq[i+1]+=d) == 0) freq.erase(i+1); }
}
int dfs2(int x, int t = 0) {
    fore(y, component[x]) d(y,1);
    d(x,1);
    int res = sz(freq);
//    for (int v = t; v--;) cout << " ";
//    cout << x/c << " " << x%c << " (, " << res << ")" << endl;
    fore(y, component[x]) fore(z, adj[y]) if(!component[x].count(z)) chmax(res, dfs2(z, t+1));
    d(x,-1);
    fore(y, component[x]) d(y,-1);
    return res;
}

void solve() {
    cin >> r >> c;
    b.resize(r);
    fore(x, b) cin >> x;

    adj.resize(r*c+1);
    is_land.resize(r*c), is_sight.resize(r*c);
    rep(i,0,r*c) if (int x=i/c, y=i%c; (b[x][y]=='.' || b[x][y]=='#'))
        is_land[i] = true;
    rep(i,0,r*c) {
        int x=i/c, y=i%c;
        switch (b[x][y]) {
            case '#': is_sight[i] = true;
            case '.': break;
            case '^': adj[x<=0 || is_land[i-c] ? r*c : i-c].pub(i); break;
            case 'v': adj[x+1>=r || is_land[i+c] ? r*c : i+c].pub(i); break;
            case '<': adj[y<=0 || is_land[i-1] ? r*c : i-1].pub(i); break;
            case '>': adj[y+1>=c || is_land[i+1] ? r*c : i+1].pub(i); break;
        }
    }

    component.resize(r*c+1); vis.resize(r*c);
    rep(i,0,r*c)
        if (dfs1(i)) {
            adj[r*c].pub(i);
//            cout << "(" << i/c << ", " << i%c << "): ";
//            fore(j, component[i]) cout << "(" << j/c << ", " << j%c << ") "; cout << "\n";
        }

    component[r*c].insert(r*c);
    cout << dfs2(r*c) << endl;
}

int32_t main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // int t; cin >> t; while (t--)
        solve();
    // cout << solve() << "\n";
    // cout << (solve() ? "YES" : "NO") << "\n";
}