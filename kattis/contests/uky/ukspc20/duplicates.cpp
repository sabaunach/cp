#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	string s;
	set<string> wordset;
	while (cin >> s) {
		if (wordset.find(s) == wordset.end())
			wordset.insert(s);
		else {
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
}
