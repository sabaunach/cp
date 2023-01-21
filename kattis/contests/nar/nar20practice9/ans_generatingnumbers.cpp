#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string s;

	cin >> t;
	int cnt[20];
	cnt[1] = 0;
	for (int i = 2; i <= 10; i++) {
		cnt[i] = cnt[i - 1] + (i - 2) * 10 + 9;
	}
	while (t--) {
		cin >> s;
		if (s.size() == 1) {
			cout << s[0] - '1' << endl;
			continue;
		}
		int F = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != '0') {
				F = 1;
				break;
			}
		}
		int ans = 0;
		if (!F) { //x0000
			ans = 1;
			if (s[0] == '1') {
				s = string(s.size() - 1, '9');
			}
			else {
				s = string(1, s[0] - 1) + string(s.size() - 1, '9');
			}
		}

		ans += cnt[s.size()];

		if (s.size() == 1) {
			ans += s[0] - '1';
		}
		else {
			int f = 1;
			int ff = 0;
			if (s[0] > '1') {
				ans += s[0] - '0' + 1;
				f = 0;
			}
			int one = 0;
			for (int i = 1; i < s.size() - 1; i++) {
				if (s[i] != '0') {
					ff++;
					if (!f) {
						f = 1;
						ans--;
					}
					ans += s[i] - '0';
					ans++;
				}
				if (s[i] == '1') one++;
			}
			ans += s[s.size() - 1] - '0';
			if (!f && s[s.size() - 1] > '0') {
				ans--;
			}
			if (s[0] > '1' && one) ans--;

		}

		cout << ans << endl;;
	}
}
