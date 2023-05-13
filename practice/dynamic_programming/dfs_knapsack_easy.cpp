#include <bits/stdc++.h>

using namespace std;

// dfs approach

// note that we need to know whether a state was visited,
// and what its value was (true or false); so we will say unvisited=-1, false=0, true=1
bool dfs(int n, vector<int>& v, unordered_set<int>& items) {
    // already visited
    if (v[n] != -1) return v[n];
    // base case
    if (items.count(n)) return v[n] = true;
    // recurrence
    return v[n] = any_of(items.begin(), items.end(), [&] (auto& item) { return dfs(n-item, v, items); });
}

int main()
{
    vector<int> items = {7,19,31};
    int target_sum = 71;

    vector<int> vis(target_sum + 1, -1);
    unordered_set<int> items_set(items.begin(), items.end());

    dfs(target_sum, vis, items_set);

    cout << (vis[target_sum] ? "YES" : "NO") << "\n";
    for (int i = 0; i <= target_sum; i++) printf("%3d",i); cout << "\n";
    for (int i = 0; i <= target_sum; i++) printf("%3d",vis[i]); cout << "\n";
}