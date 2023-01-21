#include <bits/stdc++.h>

using namespace std;

void solve() {
    
}

int main() {
	int t, n, first = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		if (first == 0)
			first = n;
		else if (n % first == 0) {
			cout << n << endl;
			first = 0;
		}
	}
}
