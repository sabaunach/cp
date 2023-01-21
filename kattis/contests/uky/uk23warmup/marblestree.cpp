#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> children;
vector<int> marbles;

// we can use a depth-first traversal of the tree.
// in a rooted tree this visits each node only once, and we can finish all children before visiting the parent.
// if we look at a subtree rooted at v we can get m = the # marbles in that subtree - # nodes in that subtree
// if m is positive, we move the excess marbles up through v. if m is negative, we will move marbles down through v.
// the total moves to solve subtree rooted at m:
//      cnt = abs(m), i.e. total # marbles moved through v, + sum over all children of solving their subtrees.
// so at each call we can return {m, total moves to solve subtree rooted at v}
pair<int, int> dfs(int v) {
    int cnt = 0, m = marbles[v] - 1;
    for (auto c: children[v]) {
        auto[c_m, c_cnt] = dfs(c);
        m += c_m;
        cnt += c_cnt;
    }
    return {m, abs(m) + cnt};
}

void solve(int n) {
    // always reassign global variables at the start of each test case
    children = vector<vector<int>>(n);
    marbles = vector<int>(n);
    // root at some node with no parents, so keep track of nodes with no parents
    unordered_set<int> root; for (int i = 0; i < n; i++) root.insert(i);

    // reading input
    for (int i = 0; i < n; i++) {
        int m, c; cin >> m >> m >> c;

        marbles[i] = m;
        for (int j = 0; j < c; j++) {
            int u; cin >> u; u--;
            children[i].push_back(u);
            // u has parent i: erase u from potential roots
            root.erase(u);
        }
    }
    cout << dfs(*root.begin()).first << endl;
}

int main() {
    for (int n; cin >> n && n != 0;)
        solve(n);
}