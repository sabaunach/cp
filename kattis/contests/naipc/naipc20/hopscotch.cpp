#include <bits/stdc++.h>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dist(k+1);
    vector<vector<pair<int, int>>> coords(k+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int in; cin >> in;
            coords[in].push_back({i, j});
            dist[in].push_back(INF);
        }
    }
    for (int i = 0; i < (int)dist[1].size(); i++) {
        dist[1][i] = 0;
    }
    for (int i = 1; i <= k; i++) {
        if (coords[i].empty()) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < (int)coords[i].size(); j++) {
            for (int l = 0; l < (int)coords[i+1].size(); l++) {
                dist[i+1][l] = min(dist[i+1][l], dist[i][j]
                     + abs(coords[i][j].first - coords[i+1][l].first)
                     + abs(coords[i][j].second - coords[i+1][l].second));
            }
        }
    }
    int minDist = INF;
    for (int i = 0; i < (int)dist[k].size(); i++) {
        minDist = min(minDist, dist[k][i]);
    }
    cout << minDist;
}
