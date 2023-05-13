#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

#define sz(x) int((x).size())

#define rep(i,a,b) for (int i = (a); i < (b); ++i)

//BinaryLifting.h
//Description: Calculate power of two jumps in a tree, to support fast upward
//jumps and LCAs. Assumes the root node points to itself.
//Time: construction O (N log N), queries O (log N)
vector<vi> treeJump(vi& P){
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i,1,d) rep(j,0,sz(P))
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}
int jmp(vector<vi>& tbl, int nod, int steps){
    rep(i,0,sz(tbl))
        if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}
int lca(vector<vi>& tbl, vi& depth, int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = jmp(tbl, a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = sz(tbl); i--;) {
        int c = tbl[i][a], d = tbl[i][b];
        if (c != d) a = c, b = d;
    }
    return tbl[0][a];
}

//RMQ.h
//Description: Range Minimum Queries on an array.
//Returns min(V[a], V[a + 1], ... V[b - 1]) in constant time.
//Usage: RMQ rmq(values);
//rmq.query(inclusive, exclusive);
//Time: O (|V | log |V | + Q)
template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return in f i f a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

//LCA.h
//Description: Data structure for computing lowest common ancestors in a
//tree (with 0 as root). C should be an adjacency list of the tree, either directed
//or undirected.
//Time: O (N log N + Q)
struct LCA {
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;
    LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
                path.push_back(v), ret.push_back(time[v]);
                dfs(C, y, v);
            }
    }
    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
//dist (a , b) {return depth [a ] + depth [ b ] − 2∗depth [ lca (a , b) ] ;}
};
