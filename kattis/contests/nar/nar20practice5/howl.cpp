/* Contest: https://open.kattis.com/contests/nar20practice5/
 * Original: https://contest.ii.uib.no/bgopen/2019/
 * Solutions: https://webcache.googleusercontent.com/search?q=cache:kArmZETuRrgJ:https://contest.ii.uib.no/bgopen/2019/bgopen19solutionslides.pdf+&cd=2&hl=en&ct=clnk&gl=us
 *
 * Problem: Howl (H)
 * Team: bbb (Seth Baunach, Brendon Bultman, Shashank Bhatt)
 * Author: Seth Baunach
 * Method: trivial; produce a valid output that is longer than the given input
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	// fast IO
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	int cnt;
	while (cin >> c) {
		cnt++;
	}
	cout << "AH";
	while (cnt--) {
		cout << "O";
	}
	cout << "W";
}
