#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

#define tcT template<class T
#define tcTU tcT, class U
tcT> using v = vector<T>;
tcTU> using pr = pair<T, U>;

typedef long long ll;
typedef pr<int, int> pii;
typedef v<int> vi;
tcT> bool chmin(T& a, T& b) { return b < a ? a = b, b : a; }
tcT> bool chmax(T& a, T& b) { return a < b ? a = b, b : a; }

tcTU> T fstTrue(T lo, T hi, U f) {
    hi++;
    while (lo < hi) {
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo--;
    while (lo < hi) {
        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    }
    return lo;
}

const int PRIME_N = 100000;
vi primes; bool is_prime[PRIME_N + 1];
void prime_sieve() {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    rep(i,2,PRIME_N + 1) if (is_prime[i]) {
        primes.push_back(i); 
        for(int j = i+i; j <= PRIME_N; j+=i) 
            is_prime[j] = false;
    }
}
int phi[PRIME_N + 1];
void phi_sieve() {
    rep(i,1,PRIME_N + 1) phi[i] = i;
    rep(i,2,PRIME_N + 1) if(is_prime[i])
        for(int j = i; j <= PRIME_N; j+=i)
            phi[j] -= phi[j]/i;
}

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,m; ll alpha; cin >> n >> m >> alpha;

    UF uf(n);
    v<pr<ll, pii>> edges;
    rep(i,0,m) {
        int u,v; ll c; cin >> u >> v >> c; u--; v--;
        edges.emplace_back(c, pii{u,v});
    }

    sort(all(edges));
    v<vi> adj(n);
    for (auto&[w, ab]: edges) {
        auto[a,b] = ab;
        adj[a].push_back(b); adj[b].push_back(a);
        if (!uf.join(ab.fi, ab.se)) {

            ll sz = 0; map<pii, bool> sn;
            function<void(int, int, ll)> dfs = [&] (int v, int par, ll c) {
                if (sn.cou]) {
                    res = c*c + sz*alpha;
                    return;
                }
                sz++;
                fore(u, adj[v]) {
                    if (u == par) continue;
                    dfs(u, v, c);
                }
                sn.erase(v);
                sz--;
            };
            dfs(a, -1, w);
            break;
        }
    }
    cout << "Poor girl\n";
}
