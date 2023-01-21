#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {

	double d;
	int n;
	while (cin >> d) {
		cin >> n;
		if (d == 0 && n == 0)
			return 0;

		double x, y;
		vector<pair<double, double> > hives;
		vector<bool> sour(n, false);
		for (int j = 0; j < n; j++) {
			cin >> x >> y;

			for (int i = 0; i < hives.size(); i++) {
				if (sqrt((y - hives[i].second)*(y - hives[i].second) + (x - hives[i].first)*(x - hives[i].first)) <= d) {
					// cout << x << " " << y << " : " << hives[i].first << " " << hives[i].second << "\n";
					sour[i] = true;
					sour[j] = true;
				}
			}

			hives.push_back({x, y});
		}

		int numsweet = 0;
		int numsour = 0;
		for (bool b: sour) {
			++(b ? numsour : numsweet);
		}

		cout << numsour << " sour, " << numsweet << " sweet\n";
	}
}
