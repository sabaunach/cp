#include <bits/stdc++.h>

using namespace std;

int MAX_D = 200;
int MAX_D2 = 40000;
int W,H,X,Y;
double a, m;s

int main() {
    cin >> a >> m;
    cin >> H >> W >> Y >> X;
    vector<vector<int>> height(H, vector<int>(W));

    map<int, vector<pair<int, int>>> height_idx;
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            cin >> height[x][y];
            height_idx[height[x][y]].push_back({x,y});
        }
    }

    for (auto[h, locs]: height_idx) {
        double entry = 6*acos(2*h/a-1)/M_PI, exit = 12 - 6*acos(2*h/a-1)/M_PI;
        cout << entry << " " << exit << endl;
        if (entry > exit) swap(entry, exit);

    }
}