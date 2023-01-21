#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	set<string> namesSet;
	unordered_map<string, int> namesList;
	unordered_map<int, string> numberList;

	int n;
	cin >> n;
	vector<set<int> > adjList;
	string line;
	getline(cin, line);
	while (n--) {
		set<int> list;
		getline(cin, line);
		istringstream iss(line);
		string key;
		string s;
		iss >> key;

		if (namesSet.insert(key).second) {
			namesList.insert(make_pair(key, namesSet.size() - 1));
			adjList.resize(namesSet.size());
		}

		while (iss >> s) {
			if (namesSet.insert(s).second) {
				namesList.insert(make_pair(s, namesSet.size() - 1));
				adjList.resize(namesSet.size());
			}
			adjList[namesList[key]].insert(namesList[s]);
			adjList[namesList[s]].insert(namesList[key]);
		}
		adjList.resize(namesSet.size());
	}
	string start, target;
	cin >> start >> target;

	vector<int> visited(namesSet.size(), 0);
	vector<int> prev(namesSet.size(), -1);
	queue<int> toVisit;

	toVisit.push(namesList[start]);
	visited[namesList[start]] = 1;
	while (prev[namesList[target]] == -1 && toVisit.size() > 0) {
		int node = toVisit.front();
		toVisit.pop();

		for (int neighbor: adjList[node]) {
			if (!visited[neighbor]) {
				toVisit.push(neighbor);
				visited[neighbor] = 1;
				prev[neighbor] = node;
			}
		}
		visited[node] = 2;
	}
	vector<int> path;
	int curr = namesList[target];
	while (curr != -1) {
		path.push_back(curr);
		curr = prev[curr];
	}
	if (path.size() == 1) {
		cout << "no route found";
		return 0;
	}
	for (auto kv: namesList) {
		numberList.insert(make_pair(kv.second, kv.first));
	}
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << numberList[path[i]] << " ";
	}
}
