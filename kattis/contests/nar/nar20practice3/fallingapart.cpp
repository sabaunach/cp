#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	while (cin >> n) {
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end());
	int s1 = 0, s2 = 0, i = 0;
	while (nums.size() > 0) {
		s1 += nums[nums.size() - 1];
		nums.erase(nums.end() - 1);
		if (nums.size() > 0) {
			s2 += nums[nums.size() - 1];
			nums.erase(nums.end() - 1);
		}
	}
	cout << s1 << " " << s2;
}
