#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ull unsigned long long

int main() {

	string s;
	cin >> s;
	char in;
	vector<char> t;
	while (cin >> in)
		t.push_back(in);

	// track active subsequences via the character they are waiting for
	// if subseqences a and b are s.t. a is a substring of b,
	// then b does not matter, we do this by indexing active subsequences
	// by which character they are waiting for to upgrade themselves, and
	// only track the one with the largest starting index (the smallest one).
	// when it upgrades, that slot for waiting for that char becomes free.
	// starts[nextChar] = largestIndexWaitingForNextChar
	vector<int> starts(t.size() + 1, -1);
	int lastStart = -1;
	ull cnt = 0;
	for (uint i = 0; i < s.size(); i++) {
		// see if any subsequences can be "upgraded"
		for (int j = starts.size() - 1; j > 0; j--) {
			if (starts[j] == -1)
				continue;
			if (s[i] == t[j]) {
				starts[j + 1] = starts[j];
				starts[j] = -1;
			}
		}
		// see if it is beginning of new subsequence
		if (s[i] == t[0]) {
			starts[1] = i; // next char we are looking for is t[1]
		}
		// see if a subsequence have been completed and count it
		if (starts[t.size()] != -1) {
			// if we can include 0 to n characters on the left substring,
			// and 0 to m characters on the right substring, we have
			// total number of substrings = (n+1)*(m+1).
			// right substring is free, however left substring we do not want
			// to overlap with an already counted subsequence, so we stop at
			// the start of the last subsequence we counted.
			cnt += (starts[t.size()] - lastStart) * (s.size() - i);
			lastStart = starts[t.size()];
			starts[t.size()] = -1;
		}
	}
	cout << cnt;
}
