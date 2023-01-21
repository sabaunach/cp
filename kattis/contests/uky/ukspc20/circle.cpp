#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

double PI = 3.1415926535897932384626; // thanks jason

int main() {
	double r;
	double m, c;
	while (cin >> r) {

		cin >> m >> c;
		if (r == 0 && m == 0 && c == 0)
			return 0;

		cout << PI * r * r << " ";

		double area = (r * 2) * (r * 2);
		double ratio = c / m;
		cout << (double)(area * ratio) << "\n";
	}
}
