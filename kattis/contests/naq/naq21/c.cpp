#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

int recur(int n, vector<int> primes, int maxn) {
	vector<int> vec;
	for (int p: primes) {
		if (n*p <= maxn)
			vec.push_back(recur(n*p, primes, maxn));
	}
	int res = n;
	for (int k: vec)
		res = max(res, k);
	return res;
}

int counter(int k, vector<int> primes) {
	auto exp = vector<int>(primes.size());
	for (int i = 0; i < primes.size(); i++) {
		while (!(k % primes[i])) {
			k /= primes[i];
			exp[i]++;
		}
	}
	int pr = 1;
	for (int i = 0; i < primes.size(); i++) {
		int e = exp[i], p = primes[i];
		if (!e) continue;
		pr *= pow(p, e - 1) * (p - 1);
	}
	return pr;
}

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

vector<int> reduce(int a, int b) {
	int d = gcd(a, b);
	if (d == 1) return {a, b};
	return reduce(a/d, b/d);
}

int32_t main() {
	int cap = 50000;
	int n; cin >> n;
	int k = 1;
	vector<int> primes;
	vector<int> sieve(cap, 0);
	for (int i = 2; true; i++) {
		if (!sieve[i]) {
			if (k * i > n) break;
			primes.push_back(i);
			k *= i;
			for (int c = i; c < cap; c += i) {
				sieve[c] = 1;
			}
		}
	}
	k = recur(k, primes, n);
	int cnt = k - counter(k, primes);
	auto frac = reduce(cnt, k);
	cout << frac[0] << "/" << frac[1] << endl;
	
}

