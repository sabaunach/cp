/* Contest: https://open.kattis.com/contests/nar20practice5/
 * Original: https://contest.ii.uib.no/bgopen/2019/
 * Solutions: https://webcache.googleusercontent.com/search?q=cache:kArmZETuRrgJ:https://contest.ii.uib.no/bgopen/2019/bgopen19solutionslides.pdf+&cd=2&hl=en&ct=clnk&gl=us
 *
 * Problem: Equilibrium (E)
 * Team: bbb (Seth Baunach, Brendon Bultman, Shashank Bhatt)
 * Author: Seth Baunach
 * Method: Greedy; select nodes with lowest cost to remove from the graph (vote).
 * Update neighbors' costs when a node is removed, and re-insert these into priority queue.
 * For nodes with the same cost of removal, the priority queue will pick the the most recently added one first.
 * (This is the purpose of the second entry in the tuple of pq.)
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int> > adjList(n);
	vector<int> cost(n);
	vector<int> votedNeighbors(n, 0);
	vector<tuple<int, int, int> > pq(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cost[i] = adjList[i].size();
		pq[i] = {-adjList[i].size(), 0, i};
	}
	vector<bool> voted(n, false);

	make_heap(pq.begin(), pq.end());
	int total = 0;
	vector<int> ans;
	int t = 1;

	while (!pq.empty()) {
		auto cost_node = pq.front();
		pop_heap(pq.begin(), pq.end()); pq.pop_back();

		if (get<0>(cost_node) != -cost[get<2>(cost_node)]) {
			// cout << get<2>(cost_node) << " is old\n";
			continue;
		}
		if (voted[get<2>(cost_node)]) {
			// cout << get<2>(cost_node) << " already voted\n";
			continue;
		}

		// cout << get<2>(cost_node) << " voting\n";
		voted[get<2>(cost_node)] = true;
		total += cost[get<2>(cost_node)];
		ans.push_back(get<2>(cost_node));

		for (int neighbor: adjList[get<2>(cost_node)]) {
			if (!voted[neighbor]) {

				votedNeighbors[neighbor]++;
				cost[neighbor] = adjList[neighbor].size() - 2 * votedNeighbors[neighbor];
				cost[neighbor] = abs(cost[neighbor]);

				// cout << cost[neighbor] << " : " << neighbor << " pushed\n";

				pq.push_back({-cost[neighbor], t++, neighbor});
				push_heap(pq.begin(), pq.end());
			}
		}
	}
	// cout << total << endl;
	for (int n: ans) {
		cout << n << " ";
	}
}
