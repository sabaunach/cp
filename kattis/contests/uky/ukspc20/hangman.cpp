#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	string word;
	cin >> word;
	unordered_set<char> letters;
	for (char c: word)
		letters.insert(c);

	int x = 10;
	char c;
	while (x > 0 && letters.size() > 0) {
		cin >> c;
		if (letters.find(c) != letters.end())
			letters.erase(c);
		else
			x--;
	}
	if (x == 0)
		cout << "LOSE";
	else
		cout << "WIN";
}
