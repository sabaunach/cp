#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 2000000000;
int SVN = 1000000; // sqN was giving wrong answer, so we increased
int sqN = 44500; //sqrt 2 billion
int cbN = 1260; // cbrt 2 billion
int frN = 212; // 4rt 2 billion

vector<bool> is_prime(SVN+1, true);
set<ll> explosive;

void sieve(int n) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}

void precomp() {
	// limit on a is probably frN and b is cbN because
	// the smallest possible x (= p0p1p2p3) has A^4 term and B^3 term
	// played it safe and let a <= cbN, b <= sqN, this worked within time
	for (int a = 1; a <= cbN; a++) {
		for (int b = -sqN; b <= sqN; b++) {
			int p1 = a + b;
			if (p1 > SVN || p1 < 0 || !is_prime[p1])
				continue;
			int p2 = a * p1 + b;
			if (p2 > SVN || p2 < 0 || !is_prime[p2])
				continue;
			int p = a * p2 + b;
			if (p > SVN || p < 0 || !is_prime[p])
				continue;
			unsigned long long x = p1 * p2;
			do {
				if (p > N / x) // if x*p > N
					break;
				x *= p;
				explosive.insert(x);
				p = a * p + b;
				if (p > SVN)
					break;
			} while (is_prime[p]);
		}
	}
}

void solve() {
	int l, h;
	cin >> l >> h;
	auto lower_it = explosive.lower_bound(l);
	auto upper_it = explosive.upper_bound(h);
	int cnt = 0;
	// subtraction not defined for tree (set) iterator, so just count
	// set is nice for sparse ranges
	for (; lower_it != upper_it; lower_it++, cnt++);
	cout << cnt << endl;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	sieve(SVN);

	precomp();

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}
