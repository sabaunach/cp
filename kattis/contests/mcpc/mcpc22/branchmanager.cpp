#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// vector<vi> treeJump(vi& P) {
//     int on = 1, d = 1;
//     while (on < sz(P)) on *= 2, d++;
//     vector<vi> jmp(d, P);
//     rep(i,1,d) rep(j,0,sz(P))
//         jmp[i][j] = jmp[i-1][jmp[i-1][j]];
//     return jmp;
// }

// int jmp(vector<vi>& tbl, int nod, int steps) {
//     rep(i,0,sz(tbl))
//         if (steps&(1<<i)) nod = tbl[i][nod];
//     return nod;
// }


vi vis, cur_edge;
vector<vi> adj;
vi par;

void elim(int p) {
    if (p == -1) return;
    while (cur_edge[p] < adj[p].size()) {
        elim(adj[p][cur_edge[p]]);
        cur_edge[p]++;
    }
}

bool process(int c, int p) {
    if (p == -1) return true;
    if (cur_edge[p] >= adj[p].size() || c < adj[p][cur_edge[p]]) return false;
    if (vis[c]) return true;
    vis[c] = true;
    while (cur_edge[p] < adj[p].size() && adj[p][cur_edge[p]] != c) {
        elim(adj[p][cur_edge[p]]);
        cur_edge[p]++;
    }
    return process(p, par[p]);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,m; cin >> n >> m;

    adj.resize(n);
    par.resize(n);
    vis.resize(n);
    cur_edge.resize(n);
    par[0] = -1;
    for (int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        par[b] = a;
    }
    for (auto& l: adj) sort(all(l));

    // vector<vi> tbl = treeJump(par);
    // path = {0};

    for (int tot = 0; tot < m; tot++) {
        int target; cin >> target; target--;

        // cout << tot << endl;
        // int k = 31 - __builtin_clz(n);
        // while (k >= 0) {
        //     if (!path.count(tbl[k][target])) target = tbl[k][target];
        //     k--;
        // }
        // path = {0};
        if (!process(target, par[target])) {
            cout << tot << endl;
            return 0;
        }
    }
    cout << m << endl;
}

