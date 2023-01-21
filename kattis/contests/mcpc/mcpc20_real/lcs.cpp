#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000;

void solve() {
	unordered_map<char, set<char>> afters;
	int n, k;
	cin >> n >> k;
	vector<string> strs;
	int loc[n][k];
	for (int t = 0; t < n; t++) {
		string s; cin >> s;
		strs.push_back(s);
		for (int i = 0; i < k; i++) {
			loc[t][s[i] - 'A'] = i;
		}
	}
	
	set<char> defAfter;
	for (int c = 'A'; c < 'A' + k; c++) {
		defAfter.insert(c);
	}
	
	for (int c = 'A'; c < 'A' + k; c++) {
		set<char> after = defAfter;
		for (int i = 0; i < n && after.size() > 0; i++) {
			int index = loc[i][c - 'A'];
			string sub = strs[i].substr(index + 1, string::npos);
			sort(sub.begin(), sub.end());
			vector<char> newAfter(k);
			set_intersection(after.begin(), after.end(), sub.begin(), sub.end(), newAfter.begin());
			after = set<char>(newAfter.begin(), newAfter.end());
		}
		afters[c] = after;
	}
	
	// longest path from each vertex
	int longest = 0;
	for (char c = 'A'; c < 'A' + k; c++) {
		vector<char> toVisit = vector<char>(afters[c].begin(), afters[c].end());
		int dist = 0;
		while (!toVisit.empty()) {
			dist++;
			vector<char> newToVisit;
			
			while (!toVisit.empty()) {
				char curr = toVisit.back(); toVisit.pop_back();
				for (auto next: afters[curr]) {
						newToVisit.push_back(next);
				}
			}
			toVisit = newToVisit;
		}
		if (dist > longest)
			longest = dist;
	}
	cout << longest << endl;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
