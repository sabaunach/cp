#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pl = pair<ll,ll>;
#define fi first
#define se second
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)


using val = pl;
val unit = {0,0};

vector<ll> labels;
vector<vector<int>> adj;
vector<unordered_map<int,int>> ind;
vector<vector<val>> pref, suff;

val merge(const val& v1, const val& v2) {
    return {v1.fi + v2.fi, v1.se + v2.se};
}

val update(const val& v1, ll d = 1) {
    return {v1.fi + v1.se, v1.se + d};
}

// The value of u's subtree that u sends to its parent v
val get(int u, int v) {
    return update(merge(pref[u][ind[u][v]], suff[u][ind[u][v]+1]), labels[u]);
}

void rec(int n, int p = -1) {
    int N = adj[n].size();
    rep(i,0,N) {
        int c = adj[n][i];
        if (c == p) break;
        rec(c,n);
        pref[n][i+1] = merge(pref[n][i], get(c,n));
    }

    rep(i,N,0) {
        int c = adj[n][i];
        if (c == p) break;
        rec(c,n);
        suff[n][i] = merge(get(c,n), suff[n][i+1]);
    }
}

void rec2(int n, int p = -1) {
    int N = adj[n].size();
    if (p != -1) {
        rep(i,ind[n][p],N) pref[n][i+1] = merge(pref[n][i], get(adj[n][i], n));
        rep(i,ind[n][p]+1,0) suff[n][i] = merge(get(adj[n][i], n), suff[n][i+1]);
    }

    fore(c,adj[n]) {
        if (c == p) continue;
        rec2(c,n);
    }
}