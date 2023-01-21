#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> v;
int r, c;

// dfs flood fill
// assume we are looking at a land tile
// mark all adjacent potential land as land & visited
void ff(int i, int j) {
    if (i < 0 || i >= r || j < 0 || j >= c) return;
    if (v[i][j] == 'W' || v[i][j] == 'X') return;
    v[i][j] = 'X';
    ff(i - 1, j); ff(i + 1, j);
    ff(i, j - 1); ff(i, j + 1);
}

int main() {
    cin >> r >> c;
    v = vector<vector<char>>(r, vector<char>(c));
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
            cin >> v[i][j];
    int cnt = 0;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
            if (v[i][j] == 'L') {
                ff(i, j);
                cnt++;
            }
    cout << cnt << endl;
}
