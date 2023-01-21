#include <bits/stdc++.h>

using namespace std;

int N, M;
unordered_map<int, unordered_set<int>> adj;
int E;
#define UMAX(a, b) a = max(a,b)
unordered_map<int, int> dist;
unordered_set<int> vis;

int dfs(int start, int i, int d) {
    if (!(vis.insert(i)).second) return -1;
    if ((dist[i] = d) == N - 1) {
        if (!adj[i].count(start)) return i;
    }
    int x;
    for (auto c: adj[i])
        if ((x = dfs(start, c, d + 1)) != -1) return x;
    vis.erase(i);
    return -1;
}

bool tryEdge(int i, int j) {
    if (E + 1 > M) return false;
    E++;
    adj[i].insert(j);
    adj[j].insert(i);
    for (int n = 0; n < N; n++) {
        dist.clear(); vis.clear();
        int c = dfs(n, n, 0);
        if (c != -1) {
            if (!tryEdge(n, c)) return false;
            break;
        }
    }
    return (E == M);
}

void solve() {
    for (int i = 2; i < N - 1; i++) {
        adj.clear();
        E = N;
        for (int j = 0; j < N; j++) {
            adj[j].insert((j + 1) % N);
            adj[(j + 1) % N].insert(j);
        }
        if (tryEdge(0, i)) {
            cout << N << " " << M << ": " << E << endl;
            for (auto a: adj) {
                for (auto c: a.second) {
                    cout << a.first << " -> " << c << endl;
                }
            }
        }
    }
}

int main() {
    for (N = 3; N <= 30; N++) {
        for (M = N; M <= N * (N - 1) / 2; M++) {
            solve();
        }
    }
}
