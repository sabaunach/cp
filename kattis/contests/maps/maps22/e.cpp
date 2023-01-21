#include <bits/stdc++.h>

using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
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

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main() {
    int L, V, R; cin >> L >> V >> R;
    long long max_flow = 0;
    Dinic * max_assign;


    unordered_map<string, int> names_to_id, color_to_id;
    vector<string> names, colors;
    vector<vector<int>> adj(L);
    for (int i = 0; i < L; i++) {
        string s; cin >> s;
        names_to_id[s] = i;
        names.push_back(s);
        int c; cin >> c;
        while (c--) {
            cin >> s;
            if (color_to_id.find(s) == color_to_id.end()) {
                color_to_id[s] = 10 + colors.size();
                colors.push_back(s);
            }
            adj[i].push_back(color_to_id[s]);
        }
    }

    for (int mask = 0; mask < (1 << L); mask++) {
        if (__builtin_popcount(mask) != V)
            continue;

        auto d = new Dinic(1001, 999, 1000);
        unordered_set<int> used_colors;
        for (int b = 0; b < L; b++) {
            if ((mask >> b) & 1) {


                d->add_edge(999, b, R);
                for(auto j : adj[b]) {
                    d->add_edge(b, j, 1);
                    used_colors.insert(j);
                }


            }
        }
        for(auto j : used_colors)
            d->add_edge(j,1000,1);

        long long flow = d->flow();
        if (flow > max_flow) {
            max_flow = flow;
            max_assign = d;
        }

    }
    unordered_map<string, vector<string>> output;
    for (auto & e: max_assign->edges) {
        if (e.flow > 0 && e.v < L) {
            output[names[e.v]].push_back(colors[e.u - 10]);
        }
    }
    cout << max_flow << " " << output.size() << endl;
    for (auto& kv: output) {
        auto loc = kv.first; auto cols = kv.second;
        cout << loc << " " << cols.size();
        for (auto& s: cols) cout << " " << s;
        cout << endl;
    }
}