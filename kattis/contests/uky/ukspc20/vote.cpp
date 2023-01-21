#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	int t, n, i, maxVotes, winner, totalVotes;
	bool tie;
	cin >> t;
	while (t--) {
		maxVotes = 0;
		totalVotes = 0;
		i = 0;
		tie = false;
		cin >> n;
		for (int j = 0; j < n; j++) {
			i++;
			int numVotes;
			cin >> numVotes;
			totalVotes += numVotes;
			if (numVotes == maxVotes) {
				tie = true;
			} else if (numVotes > maxVotes) {
				tie = false;
				maxVotes = numVotes;
				winner = i;
			}
		}
		if (tie) {
			cout << "no winner\n";
		} else if (maxVotes > totalVotes / 2) {
			cout << "majority winner " << winner << "\n";
		} else {
			cout << "minority winner " << winner << "\n";
		}
	}
}
