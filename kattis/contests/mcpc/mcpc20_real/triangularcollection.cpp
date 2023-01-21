#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<ll> nums;
	vector<vector<int>> trisets;
	int t = n;
	while (t--) {
		ll i; cin >> i;
		nums.push_back(i);
	}
	ll cnt = 0;
	for (int a = 0; a < n; a++) {
		for (int b = a + 1; b < n; b++) {
			for (int c = b + 1; c < n; c++) {
				int an = nums[a], bn = nums[b], cn = nums[c];
				if (!(an + cn > bn && an + bn > cn && bn + cn > an))
					trisets.push_back({an, bn, cn});
			}
		}
	}

	cout << cnt << endl;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
