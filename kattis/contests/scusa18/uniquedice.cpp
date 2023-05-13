#include <bits/stdc++.h>

using namespace std;

vector<int> R(vector<int> v) {
    int save = v[2];
    v[2] = v[4];
    v[4] = v[3];
    v[3] = v[5];
    v[5] = save;
    return v;
}

vector<int> U(vector<int> v) {
    int save = v[0];
    v[0] = v[2];
    v[2] = v[1];
    v[1] = v[3];
    v[3] = save;
    return v;
}

int hashy(vector<int> v) {
    vector<vector<int>> tops = {
            v,
            U(v),
            U(U(v)),
            U(U(U(v))),
            U(R(v)),
            U(U(U(R(v)))),
    };

    int hash = INT_MAX;
    for (auto &t: tops) {
        vector<vector<int>> rots = {
                t,
                R(t),
                R(R(t)),
                R(R(R(t)))
        };
        for (int i = 0; i < 4; i++) {
            int h = 0;
            for (int j = 0; j < 6; j++) {
                (h *= 6) += rots[i][j];
            }
            hash = min(hash, h);
        }
    }
    return hash;
}

int main() {
    unordered_map<int, int> m;
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> d(6);
        for (auto &x: d) cin >> x;
        for (auto &x: d) x--;
        ans = max(ans, ++m[hashy(d)]);
    }
    cout << ans << endl;
}