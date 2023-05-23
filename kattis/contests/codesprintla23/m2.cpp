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

vector<map<int, ll>> adj_m;
map<pair<int, int>, ll> extra_edges;
vector<bool> vis;
void dfs(int v, int par, set<int>& st, DSU& dsu) {
	if (vis[v]) return;
	if (st.count(v)) {
		extra_edges[{v, par}] = adj_m[v][par];
		return;
	}
	if (par != -1) dsu.unite(v, par);
	st.insert(v);
	for(auto&[u,w]: adj_m[v]) {
		if (u == par) continue;
		if (extra_edges.count({u,v}) || extra_edges.count({v,u})) continue;
		dfs(u, v, st, dsu);
	}
	vis[v] = true;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

	cerr << "reading input" << endl;
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
	vector<vpil> adj_t(n+1);
	vector<vector<tuple<int, int, ll>>> component_bridges(n+1);

	vector<bool> vis(n+1);
	function<void(int, int)> dfs2 = [&] (int v, int par) {
		if (vis[v]) return;
		vis[v] = true;
		for (auto&[u, w]: adj_m[v]) {
			if (u == par) continue;
			if (extra_edges.count({u,v}) || extra_edges.count({v,u})) continue;
			adj_t[v].emplace_back(u, w);
			dfs2(u, v);
		}
	};

	cerr << "dfs loop" << endl;
	rep(i,1,n+1) {
		set<int> st;
		dfs(i, -1, st, dsu);

		dfs2(dsu.get(i), -1);
		if (i == dsu.get(i))
		adj_t[0].emplace_back(dsu.get(i), 0);
	}

	function<void(int, int, set<int>&)> dfs3 = [&] (int v, int par, set<int>& st) {
		assert(st.insert(v).se);
		for (auto&[u, w]: adj_t[v]) {
			if (u == par) continue;
			dfs3(u, v, st);
		}
	};

	// rep(i,0,n+1) {
	// 	cerr << i << ": ";
	// 	fore(x, adj_t[i]) cerr << x.fi << " ";
	// 	cerr << endl;
	// }

	// set<int> sanity;
	// dfs3(0, -1, sanity);

	cerr << "constructing lca" << endl;
	auto lca = LCA(adj_t);
	cerr << "adding component bridges" << endl;
	for (auto&[pr, w]: extra_edges) {
		auto[a,b] = pr;
		component_bridges[dsu.get(a)].push_back({a, b, w});
		component_bridges[dsu.get(b)].push_back({b, a, w});
	}

	cerr << "answering queries" << endl;
	int q; cin >> q;
	while (q--) {
		int s, e; cin >> s >> e;

		priority_queue<pli, vpli, greater<>> pq;
		set<int> vis;
		pq.push({0, s});
		bool success = false;
		while(!pq.empty()) {
			auto [c, v] = pq.top(); pq.pop();
			if (v == e) {cout << c << "\n"; success = true; break; };
			if (!vis.insert(v).second) continue;

			if (dsu.same(v, e)) {
				pq.push({c + lca.dist(v, e), e});
			}
			for (auto&[a, b, w]: component_bridges[dsu.get(v)]) {
				ll dist = lca.dist(v, a);
				if (a == e) {
					pq.push({c + dist, e});
				}
				if (!vis.count(b)) {
					pq.push({c + dist + w, b});
				}
			}
		}
		if (!success) cout << "-1\n";
	}

}