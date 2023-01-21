#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board;
vector<int> ships;
int n, k;


int method(int ship, vector<vector<bool>> bd) {
    if (ship == (int)ships.size()) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == 'O' && bd[x][y])
                    return 0;
            }
        }
        return 1;
    }

    int cnt = 0;
    vector<vector<bool>> nb;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (bd[x][y]) {
                // if ship is length 1
                if (ships[ship] == 1) {
                    nb = bd;
                    nb[x][y] = 0;
                    cnt += method(ship+1, nb);
                } else {
                    // go through possible positions vertical
                    int off;
                    for (off = 1; off < ships[ship]; off++) {
                        if ((x + off >= n) || !bd[x + off][y])
                            break;
                    }
                    if (off == ships[ship]) {
                        nb = bd;
                        for (int i = 0; i < off; i++)
                            nb[x+i][y] = 0;
                        cnt += method(ship+1, nb);
                    }
                    // go through possible positions horizontal
                    for (off = 1; off < ships[ship]; off++) {
                        if ((y + off >= n) || !bd[x][y + off])
                            break;
                    }
                    if (off == ships[ship]) {
                        nb = bd;
                        for (int i = 0; i < off; i++)
                            nb[x][y + i] = 0;
                        cnt += method(ship+1, nb);
                    }
                }
            }
        }
    }
    return cnt;
}


int main() {
    cin >> n >> k;
    board = vector<vector<char>>(n, vector<char>(n));
    ships = vector<int>(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char in; cin >> in;
            board[i][j] = in;
        }
    }
    for (int i = 0; i < k; i++) {
        int in; cin >> in;
        ships[i] = in;
    }

    sort(ships.begin(), ships.end(), std::greater<int>());
    vector<vector<bool>> initbd(n, vector<bool>(n));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] == '.' || board[x][y] == 'O')
                initbd[x][y] = 1;
            else
                initbd[x][y] = 0;
        }
    }
    int cnt = method(0, initbd);
    cout << cnt;
}
