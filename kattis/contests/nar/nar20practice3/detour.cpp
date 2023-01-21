#include <bits/stdc++.h>

using namespace std;


bool djikstra(unordered_map<int, unordered_map<int, int> > adjList,
              vector<int> & prev, int n) {
	vector<int> cost = vector<int>(n, numeric_limits<int>::max());
	prev = vector<int>(n, -1);
	vector<bool> visited = vector<bool>(n, false);
	vector<pair<int, int> > toVisit = {{0, 0}};
	cost[0] = 0;
	visited[0] = true;

	while (toVisit.size() > 0) {
		int node_cost = toVisit.front().first;
		int node = toVisit.front().second;
		pop_heap(toVisit.begin(), toVisit.end());
		toVisit.pop_back();
		if (node_cost > cost[node]) {
			continue;
		}

		visited[node] = true;

		for (auto v_c: adjList[node]) {
			// relax edge
			if (cost[node] + v_c.second < cost[v_c.first]) {
				cost[v_c.first] = cost[node] + v_c.second;
				prev[v_c.first] = node;
				if (!visited[v_c.first]) {
					toVisit.push_back({-cost[v_c.first], v_c.first});
					push_heap(toVisit.begin(), toVisit.end());
				}
			}
		}
	}
	if (cost[1] < numeric_limits<int>::max())
		return true;
	return false;
}

int main() {
	unordered_map<int, unordered_map<int, int> > adjList;
	int n, m;
	cin >> n >> m;
	while (m--) {
		int s, d, cost;
		cin >> s >> d >> cost;
		adjList[s][d] = cost;
		adjList[d][s] = cost;
	}
	vector<int> prev;
	djikstra(adjList, prev, n);
	int node = 1, nprev = prev[node];
	while (nprev != -1) {
		adjList[nprev].erase(node);
		node = nprev;
		nprev = prev[node];
	}
	bool res = djikstra(adjList, prev, n);
	if (res == false) {
		cout << "impossible";
		return 0;
	}
	vector<int> path = {1};
	node = 1, nprev = prev[node];
	while (nprev != -1) {
		path.push_back(nprev);
		node = nprev;
		nprev = prev[node];
	}
	reverse(path.begin(), path.end());
	cout << path.size() << " ";
	for (int node: path) {
		cout << node << " ";
	}
}
