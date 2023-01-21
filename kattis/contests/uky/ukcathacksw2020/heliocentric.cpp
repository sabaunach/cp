#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	int e, m;
	int E = 365, M = 687;
	int casenumberwhyisthispartoftheoutput = 1;
	while (cin >> e >> m) {
		int days = (E - e) % E;
		m = (m + days) % M;
		while (m != 0) {
			m = (m + E) % M;
			days += E;
		}
		cout << "Case " << casenumberwhyisthispartoftheoutput << ": " << days << "\n";
		casenumberwhyisthispartoftheoutput++;
	}
}
