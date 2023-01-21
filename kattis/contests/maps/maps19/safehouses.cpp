#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> h;
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'H')
                h.push_back({i, j});
            else if (c == 'S')
                s.push_back({i, j});
        }
    }
    int max_distance = -1;
    for (auto spy: s) {
        int closestH = 100000;
        for (auto house: h) {
            closestH = min(closestH,
                abs(spy.first - house.first) + abs(spy.second - house.second));
        }
        max_distance = max(max_distance, closestH);
    }
    cout << max_distance;
}
