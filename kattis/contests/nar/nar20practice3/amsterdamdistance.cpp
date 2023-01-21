#include <bits/stdc++.h>

using namespace std;

double PI = 3.1415926535897932384626;

int main() {
	double n, m;
	double r;
	cin >> m >> n >> r;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	double dy = abs(ay - by);
	double o = (r / n) * dy;
	double theta = (abs(ax - bx) / m) * PI;
	double mindist = numeric_limits<double>::max();
	for (int k = 0; k <= min(ay, by); k++) {
		mindist = min(mindist, o + r * ((2 * k / n) + (min(ay, by) - k) * theta / n));
	}
	cout << setprecision(15);
	cout << mindist;
}
