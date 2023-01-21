#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct trie {
    trie* v[26]; bool is_key;
    trie() : is_key(false) {}

    void insert(const string& word) {
        trie * curr = this;
        for (char c: word) {
            if (!curr->v[c]) curr->v[c] = new trie();
            curr = curr->v[c];
        }
        curr->is_key = true;
    }
};

struct pq_node {
    int dist; trie* trie_node; int i, j, prev_dj;
    pq_node(int dist, trie* trie_node, int i, int j, int prev_dj) :
    dist(dist), trie_node(trie_node), i(i), j(j), prev_dj(prev_dj) {}
};

int m, n, k;
vector<vector<char>> board;
trie * trie_root;

vector<vector<vector<unordered_map<trie*, bool>>>> vis;

void solve() {
    cin >> m >> n >> k;
    board = vector<vector<char>>(m, vector<char>(n));
    vis.resize(m);
    for (auto & v: vis) { v.resize(n); for (auto & v2: v) { v2.resize(3); }}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            board[i][j] -= 'A';
        }
    }
    trie_root = new trie();
    for (string s; cin >> s;) {
        for (char & c: s) c -= 'A';
        trie_root->insert(s);
    }
    queue<pq_node> pq;

    for (int j = 0; j < n; j++) {
        auto c = trie_root->v[board[0][j]];
        if (c) {
            pq.emplace(1, c, 0, j, 0);
            vis[0][j][1][c] = true;
        }
    }

    int d[3][2] = {{0, -1}, {1, 0}, {0, 1}};

    while (!pq.empty()) {
        auto[dist, trie_node, i, j, prev_dj] = pq.front(); pq.pop();

        if (i == m - 1 && trie_node->is_key) {
            cout << dist; exit(0);
        }
        for (auto[di, dj]: d) {
            if (prev_dj != 0 && dj != 0 && prev_dj != dj) continue;
            int i2 = i + di, j2 = j + dj;
            if (i2 < 0 || i2 >= m) continue;
            if (j2 < 0 || j2 >= n) continue;

            char c = board[i2][j2];
            if (trie_node->is_key && trie_root->v[c]) {
                if (!vis[i2][j2][dj + 1][trie_root->v[c]]) {
                    pq.emplace(dist + 1, trie_root->v[c], i2, j2, dj);
                    vis[i2][j2][dj + 1][trie_root->v[c]] = true;
                }
            }
            if (trie_node->v[c]) {
                if (!vis[i2][j2][dj + 1][trie_node->v[c]]) {
                    pq.emplace(dist + 1, trie_node->v[c], i2, j2, dj);
                    vis[i2][j2][dj + 1][trie_node->v[c]] = true;
                }
            }
        }
    }
    cout << "impossible";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}
