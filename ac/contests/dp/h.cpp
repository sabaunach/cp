#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int MOD = 1000000007;
    int h,w; cin >> h >> w;
    vector<vector<int>> b(h+1, vector<int>(w+1));
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        char c; cin >> c;
        b[i][j] = (c == '.' ? 0 : -1);
    }
    b[0][0] = 1;
    for (int d = 0; d < h+w-1; d++) {
        int i = min(d,h-1), j = (d-i);
        for (int x = 0; x <= min({h-1,w-1,d,h+w-d-2}); x++) {
            if (b[i][j] != -1) {
                if (b[i+1][j] != -1) b[i+1][j] = (b[i+1][j]+b[i][j]) % MOD;
                if (b[i][j+1] != -1) b[i][j+1] = (b[i][j+1]+b[i][j]) % MOD;
            }
            i--; j++;
        }
    }
    cout << b[h-1][w-1] << endl;
}