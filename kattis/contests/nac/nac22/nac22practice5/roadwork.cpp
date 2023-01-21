#include <bits/stdc++.h>

using namespace std;

const int MAXT = 200000, DIM = MAXT*2*250, oo = 10e8;
int T, N, E = 0, W = 0;//, dp[DIM];
unordered_map<int, int> dp;
unordered_map<int, bool> vis;
// bool vis[DIM];
vector<int> ar[2], ir[2];


// maybe there's a PQ solution? ...fastest are 0.00 so
// probably the DP isn't in t but is in r, just not sure how ~

int pck(int t, int c, int e, int w) {
    return c*MAXT*E*W + w*MAXT*E + e*MAXT + t;
}

// c: which car is ready to move E: 0, W: 1
int dfs(int t, int c, pair<int, int> ind) {
    auto[e,w] = ind;
    if (e+w == E+W) return 0;
    if (e >= E && !c || w >= W && c) return oo;
    int st = pck(t,c,e,w);
    if (vis[st]) return dp[st];
    vis[st] = true;
    // let the car go
    int c_ind = c ? w : e;
    return (t - ar[c][c_ind] > ir[c][c_ind]) + min
    (
        dfs(t+T,!c,{e + !c, w + c}),
        dfs(max(t+3, ar[c][(c_ind) + 1]),c,{e + !c, w + c})
    );
}

int main() {
    cin >> T >> N;
    vector<tuple<int, int, int>> ar_or_ir[2];
    for (int i = 0; i < N; i++) {
        char dir; int arr, irr;
        cin >> dir >> arr >> irr;
        ar_or_ir[dir != 'E'].push_back({arr,i,irr});
        dir == 'E' ? E++ : W++;
    }
    for (auto dir: {0,1}) {
        sort(ar_or_ir[dir].begin(), ar_or_ir[dir].end());
        for (auto[arr,_,irr]: ar_or_ir[dir]) {
            ar[dir].push_back(arr);
            ir[dir].push_back(irr);
        }
        ar[dir].push_back(oo);
    }

    cout << min(
                E > 0 ? dfs(ar[0][0], 0, {0,0}) : oo,
                W > 0 ? dfs(ar[1][0], 1, {0,0}) : oo
            );
}