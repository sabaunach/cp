#include <bits/stdc++.h>

// didn't get it to work

typedef unsigned long long ull;

using namespace std;

double PI = 3.1415926535897932384626;

int main() {

	vector<int> fib = {2, 3};
	vector<bool> seen;
	int k;
	cin >> k;
	while (cin >> k) {
		seen = vector<bool>(1001, 0);
		// seen[1] = 1;
		int i = 0;
		for (int j = 0; j < 1000; j++) {
			if (fib.size() <= j) {
				fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
			}
			int num = fib[j] % k;
			seen[num] = 1;
		}
		while (true) {
			int num = fib[i] % k;
			if (seen[num])
				break;
			i++;
		}
		cout << i << "\n";
	}
}
