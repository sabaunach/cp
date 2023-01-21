#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

double PI = 3.1415926535897932384626;

int main() {
	vector<double> sums(51);
	vector<double> nums(51);
	nums[1] = 1;
	sums[1] = 1;
	nums[2] = 4;
	sums[2] = sums[1] + 1;
	for (int i = 3; i < nums.size(); i++) {
		nums[i] = nums[i - 1] * 3;
		sums[i] = sums[i - 1] + nums[i]/((pow(pow(2.0, i - 1), 2.0)));
	}

	int r, n;
	cin >> n;
	cout << setprecision(12);
	while (cin >> r >> n) {
		cout << PI * r * r * sums[n] << "\n";
	}
}
