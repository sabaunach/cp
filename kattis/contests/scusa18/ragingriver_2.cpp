#include <bits/stdc++.h>

using namespace std;

int main() {
    int P,R,L; cin >> P >> R >> L;
    unordered_map<int, unordered_set<int>> adj;
    for (int i = 0; i < L; i++) {
        int a,b; cin >> a >> b;
        a+=2; b+=2;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int t = 0;
    for (int i = 0; i < P; i++) {
        queue<int> q; q.push(0);
        vector<int> vis(R+2, -1);
        while (!q.empty()) {
            auto top = q.front(); q.pop();
            for (auto x: adj[top]) {
                if (vis[x] == -1) {
                    vis[x] = top;
                    q.push(x);
                }
            }
            if (vis[1] != -1) break;
        }
        if (vis[1] == -1) {
            cout << P-i << " people left behind\n";
            return 0;
        }
        auto cur = 1;
        while (cur != 0) {
            t++;
            adj[cur].erase(vis[cur]);
            adj[vis[cur]].erase(cur);
            cur = vis[cur];
        }
    }
    cout << t << endl;
}