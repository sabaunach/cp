#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ull;

const ll MOD = 998244353;
const int n = 1e5 + 2;

vector<ull> ninepower(n);
vector<ull> precomp(n);

void precompute() {
	precomp[0] = 1;
	ninepower[0] = 1;
	precomp[1] = 9;
	ninepower[1] = 9;
	for (int i = 2; i < n; i++) {
		ninepower[i] = (ninepower[i - 1] * 9) % MOD;
		precomp[i] = (ninepower[i] + precomp[i - 1]) % MOD;
	}
}

 // [0, 10^n)
 // [0, n)
void solve() {
	string l, u;
	cin >> l >> u;
	ull r_l = 0;
	ull r_u = 0;
	
	for (int i = 0; i < l.size(); i++) {
		ll num = l[i] - '0';
		r_l += precomp[l.size() - i - 1] + (num - 1)*ninepower[l.size() - i - 1];
	}
	for (int i = 0; i < u.size(); i++) {
		ll num = u[i] - '0';
		r_u += precomp[u.size() - i - 1] + (num - 1)*ninepower[u.size() - i - 1];
	}
	cout << r_l << " " << r_u << endl;
	cout << r_u - r_l;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	precompute();
	solve();

	return 0;
}
