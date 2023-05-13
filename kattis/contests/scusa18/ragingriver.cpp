#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define emb emplace_back
#define pub push_back

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vi> adj;
    int n, m = 0;
    int s, t;
    vi level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, ll cap) {
        edges.emb(v, u, cap);
        edges.emb(u, v, 0);
        adj[v].pub(m);
        adj[u].pub(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            auto tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (auto pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main() {
    int p,r,l; cin>>p>>r>>l;
    Dinic d(r+2,r,r+1);
    vector<vi> adj(r+2);
    for(int i = 0; i < l; i++) {
        int a,b;cin>>a>>b;
        if(a<0)a+=r+2;
        if(b<0)b+=r+2;
//        cout<<a<< " "<<b<<endl;
        adj[a].pub(b);
        adj[b].pub(a);
//        d.add_edge(a,b,1);
//        d.add_edge(b,a,1);
    }
    vi depth(r+2,10000000);
    depth[r] = 0;
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        int n = q.front();q.pop();
        if (n==r+1) continue;
        for(auto nn : adj[n]) {
            if (depth[nn]>depth[n]+1){
                depth[nn]=depth[n]+1;
                q.push(nn);
            }
        }
    }

    for(int i = 0; i < r+2;i++) {
        for(auto j : adj[i]) {
            if((i != r+1 && depth[i] + 1 == depth[j]) || (j == r+1)) {
//                cout << i << " " << j << endl;
                d.add_edge(i, j, 1);
            }
        }
    }

    ll f = d.flow();
    if (f != p) {
        cout << p-f << " people left behind\n";
    } else{
        int t = 0;
        for(auto e : d.edges) {
//            cout << e.v << " " << e.u << " " << e.cap << " " << e.flow << endl;
            t += abs(e.flow);
        }
        cout << t/2 << endl;
    }
}