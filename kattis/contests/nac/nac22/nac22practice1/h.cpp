#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;

    const ll oo = 10e12;

    vector<vector<pair<int, int>>> adj(N);
    vector<vector<pair<int, int>>> adj_(N);

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        // transpose
        adj_[b].emplace_back(a, w);
    }

}