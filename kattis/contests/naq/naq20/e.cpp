#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> values;
vector<unordered_set<int> > children;
vector<int> parent;
int INF = 1000000001;

int recursive(int cur) {
	int total = 0;

	for (auto &i: children[cur]) {
		if (!children[i].empty()) {
			// recurse on non-leaf children
			total += recursive(i);
		}
	}

	// all non-leaf children have been dealt with
	// all children are now leaves

	// base case: root
	if (values[cur] == INF) {
		// subtract from leaves 2 at time
		// needs a pq

		priority_queue<pair<int, int> > pq;
		for (auto &i: children[cur]) {
			pq.push({values[i], i});
		}
		int i = 0;
		while (pq.size() > 1) {
			i++;
			auto val1 = pq.top(); pq.pop();
			auto val2 = pq.top(); pq.pop();
			val1.first--;
			val2.first--;
			if (val1.first != 0)
				pq.push(val1);
			if (val2.first != 0)
				pq.push(val2);
		}
		return total + i + ((pq.empty()) ? 0 : pq.top().first);
	}

	int sum = 0;
	for (auto &i : children[cur]) {
		sum += values[i];
	}

	if (sum <= values[cur]) {
		values[cur] -= sum;
		children[cur].clear();
		return total + sum;
	} else {
		children[parent[cur]].erase(cur);
		// subtract from leaves
		// needs a pq

		priority_queue<pair<int, int> > pq;
		int p = values[cur];
		for (auto &i: children[cur]) {
			pq.push({values[i], i});
		}
		for (int i = 0; i < values[cur]; i++) {
			auto val = pq.top(); pq.pop();
			val.first--;
			pq.push(val);
		}
		while (!pq.empty()) {
			auto val = pq.top(); pq.pop();
			values[val.second] = val.first;
		}
		values[cur] = INF;

		return total + recursive(cur);
	}
}

void solve() {
	int n;
	cin >> n;
	values = vector<int>(n, -1);
	parent = vector<int>(n, -1);
	children = vector<unordered_set<int> >(n);
	int root = -1;
	for (int i = 0; i < n - 1; i++) {
		int paren, child, value;
		cin >> paren >> child >> value;
		if (root == -1)
			root = paren;

		if (values[child] == -1) {
			children[paren].insert(child);
			parent[child] = paren;
			values[child] = value;
		} else { // if child is already child, flip
			children[child].insert(paren);
			parent[paren] = child;
			values[paren] = value;
		}
	}

	values[root] = INF;
	cout << recursive(root);
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
