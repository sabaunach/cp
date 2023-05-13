#include <bits/stdc++.h>

using namespace std;

// bfs approach
int main()
{
    vector<int> items = {7,19,31};
    int target_sum = 71;

    vector<int> vis(target_sum + 1); // vis[i] = 1 if we can make sum i
    list<int> q; // sums we reached on previous iteration
    for (auto& item: items) {
        vis[item] = 1;
        q.push_back(item);
    }

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int sum = q.front(); q.pop_front();
            for (auto& item: items) {
                if (sum + item > target_sum)
                    continue;
                if (!vis[sum + item]) {
                    vis[sum + item] = 1;
                    q.push_back(sum + item);
                }
            }
        }
    }

    cout << (vis[target_sum] ? "YES" : "NO") << "\n";
    for (int i = 0; i <= target_sum; i++) printf("%3d",i); cout << "\n";
    for (int i = 0; i <= target_sum; i++) printf("%3d",vis[i]); cout << "\n";
}