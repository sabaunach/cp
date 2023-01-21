#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<unordered_set<int> > g(n);
	vector<unordered_set<int> > g2(n);
	while (m--) {
		int a, b; cin >> a >> b; a--, b--;
		for (int neighbor: g[a]) {
			g2[b].insert(neighbor);
			g2[neighbor].insert(b);
		}
		for (int neighbor: g[b]) {
			g2[a].insert(neighbor);
			g2[neighbor].insert(a);
		}
		g[a].insert(b);
		g[b].insert(a);
	}

	vector<int> visited(n, 0);
	vector<int> toVisit;
	for (int i = 0; i < n; i++) {
		toVisit.push_back(i);
	}

	vector<int> uf(n, -1);
	vector<int> uf2(n, -1);

	while (!toVisit.empty()) {
		int node = toVisit.back(); toVisit.pop_back();
		if (visited[node] == 2)
			continue;

		visited[node] = 2;
		for (int neighbor: g2[node]) {
			if (visited[neighbor] == 0) {
				visited[neighbor] = 1;
				// toVisit.push_back(neighbor);
				if (uf2[neighbor] == -1)
					uf2[neighbor] = node;
			}
		}
	}


	visited(n, 0);
	for (int i = 0; i < n; i++) {
		toVisit.push_back(i);
	}
	while (!toVisit.empty()) {
		int node = toVisit.back(); toVisit.pop_back();
		if (visited[node] == 2)
			continue;

		visited[node] = 2;
		for (int neighbor: g[node]) {
			if (visited[neighbor] == 0) {
				visited[neighbor] = 1;
				// toVisit.push_back(neighbor);
				if (uf[neighbor] == -1)
					uf[neighbor] = node;
			}
		}
	}

	int cnt = 0;
	for(int i: uf2) {
		// if two components are connected in g and g2,
		// a pair can be connected in one
	}


	cout << cnt - 1 << endl;

}
