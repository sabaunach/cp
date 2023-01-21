#include <bits/stdc++.h>

using namespace std;

vector<unordered_set<int>> adj;
void dfs1(int i = 0) {
    for (auto c: adj[i]) {
        adj[c].erase(i);
        dfs1(c);
    }
}

int N, K;
typedef pair<int, int> pii;
pair<pii, pii>  dfs2(int i) {
    if (adj[i].empty()) {
        return {{1, 1}, {2, 2}};
    }
    // color node i with color j
    vector<int> c(K+1, 0);
    for (int j=1; j<=K; j++) c[j] = j;
    for (auto ch: adj[i]) {
        auto ch_c = dfs2(ch);
        // increment c[j] by min or next min
        for (int j=1; j<=K; j++) c[j] += (ch_c.first.first == j) ? ch_c.second.second : ch_c.first.second;
    }
    // min cost colorings for node i
    pii min1 = {1, c[1]}, min2 = {2, c[2]};
    if (min1.second > min2.second) swap(min1, min2);
    for (int j=3; j<=K; j++) {
        if (c[j] < min1.second) {
            min2 = min1;
            min1 = {j, c[j]};
        } else if (c[j] < min2.second) {
            min2 = {j, c[j]};
        }
    }
    return {min1, min2};
}

int main() {
    cin >> N >> K;
    if (N==1) {
        cout << "1" << endl;
        return 0;
    } else if (K == 1) {
        cout << "-1" << endl;
        return 0;
    }
    adj.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        adj[x-1].insert(y-1);
        adj[y-1].insert(x-1);
    }
    dfs1();

    cout << dfs2(0).first.second;
}