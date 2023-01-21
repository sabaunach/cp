#include <bits/stdc++.h>

using namespace std;

int solve(int N, int M) {
    vector<vector<int>> a, h, v;
    a = h = v = vector<vector<int>>(N, vector<int>(M));
    // first get differences horz & vert
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
            cin >> a[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < M-1; j++)
            h[i][j] = a[i][j+1] - a[i][j];
    for (int i = 0; i < N-1; i++) for (int j = 0; j < M; j++)
            v[i][j] = v[i+1][j] - v[i][j];

    // get top left of each sq
    unordered_set<int> go, go2;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        go.emplace(i*M+j);
    }

    int lv = 0;
    while (!(go.empty())) {
        lv++;
        swap(go2, go);
        go.clear();
        for (auto x: go2) {
            auto i = x%M, j = x/M;
            if ((i+1)>=N||(j+1)>=M
//            || !(h[i][j] == h[i+1][j] && v[i][j] == v[i+1][j] && go2.count((i+1)*M+j))
//            || !(h[i][j] == h[i][j+1] && v[i][j] == v[i][j+1] && go2.count((i)*M+j+1))
//            || !(h[i][j] == h[i+1][j+1] && v[i][j] == v[i+1][j+1] && go2.count((i+1)*M+j+1))
//            || !(h[i][j] == h[i+lv][j] && go2.count((i+lv)*M+j))
//            || !(h[i][j] == h[i][j+lv] && go2.count(i*M+(j+lv)))
//            || !(h[i][j] == h[i+lv][j+lv] && go2.count((i+lv)*M+(j+lv)))
//            || !(v[i][j] == v[i+lv][j] && go2.count((i+lv)*M+j))
//            || !(v[i][j] == v[i][j+lv] && go2.count(i*M+(j+lv)))
//            || !(v[i][j] == v[i+lv][j+lv] && go2.count((i+lv)*M+(j+lv)))
            ) continue;
            go.emplace(x);
        }
    }
    return lv*lv;
}

int main() {
    int N, M;
    while (cin >> N >> M && N)
        cout << solve(N, M) << endl;

}