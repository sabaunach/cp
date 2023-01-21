#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	string t[128]; // T_i i in alphabet
	int s_t[128]; // |T_i| (size of each T)
	ll s_i = 0, // index in S
	   p_i = 0, // index in P
	   k, m;
	string s;
	cin >> s;
	for (char i = 'a'; i <= 'z'; i++) {
		string in; cin >> in;
		t[i] = in;
		s_t[i] = in.length();
	}
	cin >> k >> m;
	vector<tuple<ll, ll, char> > cases;
	for (int i = 0; i < m; i++) {
		int in; cin >> in;
		cases.push_back({in--, i, '\0'});
	}
	sort(cases.begin(), cases.end());






	for (ll c: cases) {
	}



	for (int i = 0; i < m; i++) {
		cases[i] = {get<2>(cases[i]), get<1>(cases[i]), get<3>(cases[i])};
	}
	sort(cases.begin(), cases.end());
	for (auto ans: cases) {
		cout << get<3>(ans) << endl;
	}
}
