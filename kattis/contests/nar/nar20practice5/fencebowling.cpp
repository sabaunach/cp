/* Contest: https://open.kattis.com/contests/nar20practice5/
 * Original: https://contest.ii.uib.no/bgopen/2019/
 * Solutions: https://webcache.googleusercontent.com/search?q=cache:kArmZETuRrgJ:https://contest.ii.uib.no/bgopen/2019/bgopen19solutionslides.pdf+&cd=2&hl=en&ct=clnk&gl=us
 *
 * Problem: Fencebowling (F)
 * Team: bbb (Seth Baunach, Brendon Bultman, Shashank Bhatt)
 * Author: Seth Baunach
 * Method: binary search, simulating each (I misread the problem so b in the calculations corresponds to b complement, it is turned into b at the end)
 */
#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265359;
const double ERR = .00000001;

int main() {

	// ans is between 0 and 90 degrees
	double lower = 0;
	double upper = PI/2;
	double b = PI/4;
	double prev = 0;

	// input

	int k;
	double w, l;
	cin >> k >> w >> l;

	// calculate bounces

	double bounceAng;

	while (abs(b - prev) > ERR) {
		prev = b;
		bounceAng = b;

		double xBounce = (w/2) / tan(bounceAng);
		double xTotal = xBounce;
		bounceAng = PI/2 - atan(2 * tan(PI/2 - bounceAng));

		// bounces
		for (int i = 1; i < k; i++) {
			xBounce = (w) / tan(bounceAng);
			xTotal += xBounce;
			bounceAng = PI/2 - atan(2.0 * tan(PI/2 - bounceAng));
		}

		double yStrike = (l - xTotal) * tan(bounceAng);
		if (xTotal > l) {
			// cout << "ub: " << b * (180/PI);
			// undershot bounces
			lower = b;
			b = (upper + lower) / 2;
		} else if (yStrike > w) {
			// cout << "ob: " << b * (180/PI);
			// not enough bounces
			upper = b;
			b = (upper + lower) / 2;
		} else if (yStrike > w/2) {
			// cout << "o: " << b * (180/PI);
			// overshot
			upper = b;
			b = (upper + lower) / 2;
		} else {
			// cout << "u: " << b * (180/PI);
			// undershot
			lower = b;
			b = (upper + lower) / 2;
		}
		// cout << endl;
	}
	cout << setprecision(10);
	cout << 90 - b * (180/PI);
}
