#include <bits/stdc++.h>
#include <set>
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

typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
using vi = vector<int>;
using vpli = vector<pli>;
using vpil = vector<pil>;
using mpil = map<int, ll>;

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
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	vector<ll> depth;
	RMQ<int> rmq;

	LCA(vector<vpil>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vpil>& C, int v, int par) {
		time[v] = T++;
		for (auto[y, w] : C[v]) if (y != par) {
			depth[y] = depth[v] + w;
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}

	ll dist(int a, int b) {
		return depth[a] + depth[b] - 2LL*depth[lca(a,b)];
	}
};

struct DSU {
    vi v; explicit DSU(int n) : v(n, -1) {}
    int get(int x) { return v[x] < 0 ? x : v[x] = get(v[x]); }
    bool same(int x, int y) { return get(x) == get(y); }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (v[x] < v[y]) swap(x, y);
        v[y] += v[x]; v[x] = y;
        return true;
    }
};

ll djik(int s, int e, vector<mpil>& adj) {
    priority_queue<pli, vpli, greater<>> pq;
    set<int> vis;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [v_c, v] = pq.top(); pq.pop();
        if (v == e) return v_c;
        if (!vis.insert(v).second) continue;
        for(auto&[u, w]: adj[v]) {
            ll u_c = w + v_c;
            if (vis.count(u)) continue;
            pq.push({u_c, u});
        }
    }
    return -1;
}

vector<map<int, ll>> adj_m;
vector<tuple<int, int, ll>> extra_edges;
vector<bool> vis;
bool dfs(int v, int par, set<int>& st, DSU& dsu) {
	if (vis[v]) return true;
	if (st.count(v)) {
		extra_edges.emplace_back(v, par, adj_m[v][par]);
		adj_m[v].erase(par);
		return false;
	}
	if (par != -1) dsu.unite(v, par);
	st.insert(v);
	vector<int> to_erase;
	for(auto&[u,w]: adj_m[v]) {
		if (u == par) continue;
		if (!dfs(u, v, st, dsu)) to_erase.pub(u);
	}
	fore(u, to_erase) adj_m[v].erase(u);
	vis[v] = true;
	return true;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

	int n; cin >> n;
	adj_m.resize(n+1);
	rep(i,1,n+1) {
		int j; ll w; cin >> j >> w;
		if (adj_m[i][j]) {
			chmin(adj_m[i][j], w);
			chmin(adj_m[j][i], w);
		} else {
			adj_m[i][j] = adj_m[j][i] = w;
		}
	}
	int l; cin >> l;
	rep(t,0,l) {
		int i, j; ll w; cin >> i >> j >> w;
		if (adj_m[i][j]) {
			chmin(adj_m[i][j], w);
			chmin(adj_m[j][i], w);
		} else {
			adj_m[i][j] = adj_m[j][i] = w;
		}
	}

	DSU dsu(n+1);
	vis.resize(n+1);
	rep(i,1,n+1) {
		set<int> st;
		dfs(i, -1, st, dsu);
	}

	vector<vpil> adj_t(n+1);
	vector<bool> vis(n+1);
	function<void(int, int)> dfs2 = [&] (int v, int par) {
		if (vis[v]) return;
		vis[v] = true;
		for (auto&[u, w]: adj_m[v]) {
			if (u == par) continue;
			adj_t[v].emplace_back(u, w);
			dfs2(u, v);
		}
	};
	set<int> reps;
	rep(i,1,n+1) {
		dfs2(dsu.get(i), -1);
		reps.insert(dsu.get(i));
	}
	fore(x, reps) adj_t[0].emplace_back(x, 0);
	auto lca = LCA(adj_t);

	vector<mpil> adj_temp(n+1);
	rep(i,0,sz(extra_edges)) {
		auto[a1,b1,w1] = extra_edges[i];
		if (adj_temp[a1][b1]) {
			adj_temp[a1][b1] = adj_temp[b1][a1] = min(adj_temp[a1][b1], w1);
		}
		else {
			adj_temp[a1][b1] = adj_temp[b1][a1] = w1;
		}
		if (dsu.same(a1, b1)) {
			adj_temp[a1][b1] = adj_temp[b1][a1] = min(adj_temp[a1][b1], lca.dist(a1, b1));
		}

		rep(j,i+1,sz(extra_edges)) {
			auto[a2,b2,w2] = extra_edges[j];
			for(auto[a,b]: vector<pair<int,int>>{
				{a1, a2}, {a1,b2}, {b1,a2}, {b1,b2}
				}) {
				if (a != b && dsu.same(a, b)) {
					if (adj_temp[a][b]) {
						adj_temp[a][b] = adj_temp[b][a] = min(adj_temp[a][b], lca.dist(a, b));
					} else {
						adj_temp[a][b] = adj_temp[b][a] = lca.dist(a, b);
					}
				}
			}
		}
	}

	int q; cin >> q;
	while (q--) {
		int s, e; cin >> s >> e;
		vector<mpil> adj(adj_temp);
		if (dsu.same(s, e)) {
			if (adj[s][e]) {
				adj[s][e] = adj[e][s] = min(adj[s][e], lca.dist(s,e));
			}
			else {
				adj[s][e] = adj[e][s] = lca.dist(s, e);
			}
		}
		rep(i,0,sz(extra_edges)) {
			auto[e_a,e_b,e_w] = extra_edges[i];
			for(auto[a,b]: vector<pair<int,int>>{
				{s, e_a}, {s, e_b}, {e, e_a}, {e, e_b}
				}) {
				if (a != b && dsu.same(a, b)) {
					if (adj_temp[a][b]) {
						adj_temp[a][b] = adj_temp[b][a] = min(adj_temp[a][b], lca.dist(a, b));
					} else {
						adj_temp[a][b] = adj_temp[b][a] = lca.dist(a, b);
					}
				}
			}
		}
		cout << djik(s,e,adj_temp) << "\n";
	}

}