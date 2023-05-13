#include <bits/stdc++.h>

using namespace std;

// iterative approach
// based off the fact that when we visit i, if we visited all sums before i,
// we will have visited any sub-problems that would have helped us answer i
int main()
{
    vector<int> items = {7,19,31};
    int target_sum = 71;

    vector<int> vis(target_sum + 1); // vis[i] = 1 if we can make sum i
    for (auto& item: items) vis[item] = 1;

    for (int i = 0; i <= target_sum; i++) {
        if (!vis[i]) continue;
        for (auto& item: items) {
            if (i + item > target_sum) continue;
            vis[i + item] = 1;
        }
    }

    cout << (vis[target_sum] ? "YES" : "NO") << "\n";
    for (int i = 0; i <= target_sum; i++) printf("%3d",i); cout << "\n";
    for (int i = 0; i <= target_sum; i++) printf("%3d",vis[i]); cout << "\n";
}