#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int R, C;
int ti, tj, ri, rj;
struct square {
    // 0: can stand on sq (no knights protecting sq)
    // >0: # knights protecting sq
    // <0: cannot ever stand on sq (knight protected by knight)
    int status = 0;
    bool vis = false, seen = false, knight = false;
};
vector<vector<square>> board;
int dij[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void visit(int i, int j) {
    board[i][j].vis = true;
    if (i == ti && j == tj) {
        cout << "yes";
        exit(0);
    }
    // rook is moving through knights... this shouldn't be possible
    if (board[i][j].knight) {
        board[i][j].knight = false;
        for (auto[di, dj]: dij) {
            int i2 = i + di, j2 = j + dj;
            if (i2 < 0 || i2 >= R || j2 < 0 || j2 >= C) continue;
            board[i2][j2].status--;
            if (!board[i2][j2].status && board[i2][j2].seen) {
                visit(i2, j2);
            }
        }
    }
    for (int i2 = i - 1; i2 >= 0; i2--) {
        board[i2][j].seen = true;
        if (board[i2][j].vis) break;
        if (!board[i2][j].status) visit(i2, j);
        if (board[i2][j].knight) break;
    }
    for (int i2 = i + 1; i2 < R; i2++) {
        board[i2][j].seen = true;
        if (board[i2][j].vis) break;
        if (!board[i2][j].status) visit(i2, j);
        if (board[i2][j].knight) break;
    }
    for (int j2 = j - 1; j2 >= 0; j2--) {
        board[i][j2].seen = true;
        if (board[i][j2].vis) break;
        if (!board[i][j2].status) visit(i, j2);
        if (board[i][j2].knight) break;
    }
    for (int j2 = j + 1; j2 < C; j2++) {
        board[i][j2].seen = true;
        if (board[i][j2].vis) break;
        if (!board[i][j2].status) visit(i, j2);
        if (board[i][j2].knight) break;
    }
}

void solve() {
    visit(ri, rj);
    cout << "no";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> R >> C;

    board.resize(R);
    for (auto & v: board) v.resize(C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c; cin >> c;
            if (c == '.') continue;
            else if (c == 'K') { board[i][j].knight = true; }
            else if (c == 'T') { ti = i; tj = j; }
            else { ri = i; rj = j; }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j].knight) {
                for (auto[di, dj]: dij) {
                    int i2 = i + di, j2 = j + dj;
                    if (i2 < 0 || i2 >= R || j2 < 0 || j2 >= C) continue;
                    if (board[i2][j2].knight) board[i2][j2].status = -1;
                    else board[i2][j2].status++;
                }
            }
        }
    }

    solve();
}
