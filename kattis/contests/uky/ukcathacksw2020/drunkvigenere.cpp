#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	string s, k;
	cin >> s >> k;
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 1)
			cout << (char)(((s[i] + (k[i] - 65)) - 65) % 26 + 65);
		else
			cout << (char)(((s[i] - (k[i] - 65)) - 65 + 26) % 26 + 65);
	}
}
