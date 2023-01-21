#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll ret = LLONG_MAX, n, m, k, a, b, numcc = 0;
// x -> y and y->x
set<ll> xfirst, yfirst;
// 1 = unvis, 2 = vis, 3 = empty
unordered_map<ll, unordered_map<ll, int>> g;
unordered_map<ll, unordered_map<ll, unordered_map<ll, bool>>> ccs;


void dfs(ll x, ll y){
	if(g[x][y] != 1) return;
	g[x][y] = 2;
	if(x-1 >= 1){
		if(g[x-1][y] == 0){
			g[x-1][y] = 3;
			ccs[numcc][x-1][y] = 1;
		}
		else dfs(x-1, y);
	}
	if(y-1 >= 1){
		if(g[x][y-1] == 0){
			g[x][y-1] = 3;
			ccs[numcc][x][y-1] = 1;
		}
		else dfs(x, y-1);
	}
	if(x+1 <= n){
		if(g[x+1][y] == 0){
			g[x+1][y] = 3;
			ccs[numcc][x+1][y] = 1;
		}
		else dfs(x+1, y);
	}
	if(y+1 <= m){
		if(g[x][y+1] == 0){
			g[x][y+1] = 3;
			ccs[numcc][x][y+1] = 1;
		}
		else dfs(x, y+1);
	}
	dfs(x+1, y+1);
	dfs(x+1, y-1);
	dfs(x-1, y+1);
	dfs(x-1, y-1);
}

ll good(ll cc, ll x, ll y){
	if(x < 0 || y < 0 || x > n || y > m || ccs[cc][x][y] == 0) return 0;
	//cout << x << " " << y << " " << ccs[cc][x][y] << endl;
	ll r = 1;
	ccs[cc][x][y] = false;
	if(ccs[cc][x+1][y] == 1) r += good(cc, x+1, y);
	if(ccs[cc][x-1][y] == 1) r += good(cc, x-1, y);
	if(ccs[cc][x][y+1] == 1) r += good(cc, x, y+1);
	if(ccs[cc][x][y-1] == 1) r += good(cc, x, y-1);
	if(x-1 >= 1 && g[x-1][y] == 0){
		if(y-1 >= 1 && ccs[cc][x-1][y-1] == 1) r += good(cc, x-1, y-1);
		if(y+1 <= m && ccs[cc][x-1][y+1] == 1) r += good(cc, x-1, y+1);
	}
	if(y-1 >= 1 && g[x][y-1] == 0){
		if(x-1 >= 1 && ccs[cc][x-1][y-1] == 1) r += good(cc, x-1, y-1);
		if(x+1 <= n && ccs[cc][x+1][y-1] == 1) r += good(cc, x+1, y-1);
	}
	if(x+1 >= 1 && g[x+1][y] == 0){
		if(y-1 >= 1 && ccs[cc][x+1][y-1] == 1) r += good(cc, x+1, y-1);
		if(y+1 <= m && ccs[cc][x+1][y+1] == 1) r += good(cc, x+1, y+1);
	}
	if(y+1 >= 1 && g[x][y+1] == 0){
		if(x-1 >= 1 && ccs[cc][x-1][y+1] == 1) r += good(cc, x-1, y+1);
		if(x+1 <= n && ccs[cc][x+1][y+1] == 1) r += good(cc, x+1, y+1);
	}
	return r;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	if(k == n * m) {
		cout << -1 << endl;
		return 0;
	}
	ret = min(n, m);
	xfirst.insert(0);
	xfirst.insert(n+1);
	yfirst.insert(0);
	yfirst.insert(m+1);
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		g[a][b] = 1;
		xfirst.insert(a);
		yfirst.insert(b);
		auto it = xfirst.lower_bound(a);
		if(a - *prev(it) - 1 > 0) ret = min(ret, a - *prev(it) - 1);
		it++;
		if(*it - a - 1 > 0) ret = min(ret, *it - a - 1);
		it = yfirst.lower_bound(b);
		if(b - *prev(it) - 1 > 0) ret = min(ret, b - *prev(it) - 1);
		it++;
		if(*it - b - 1 > 0) ret = min(ret, *it - b - 1);
	}
	for(auto &i : g){
		for(auto &j : i.second){
			if(j.second != 2){
				numcc++;
				dfs(i.first, j.first);
				ll cnt = 0;
				for(auto &k : ccs[numcc]){
					cnt += k.second.size();
				}
				if(cnt == 0) continue;
				ll gg = good(numcc, ccs[numcc].begin()->first, ccs[numcc].begin()->second.begin()->first);
				if(cnt != gg){
					return cout << -1 << endl, 0;
				}
			}
		}
	}

	cout << ret << endl;
	return 0;
}