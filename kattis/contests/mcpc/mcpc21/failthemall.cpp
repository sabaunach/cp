#include <bits/stdc++.h>

using namespace std;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)
#define ALL(a) (a).begin(), (a).end()

const int Q_MAX = 100;
unordered_set<int> adj[Q_MAX * 2];
int n, k;
int ind = 1;
int t_index[Q_MAX * 2 + 1],
    t_lowlink[Q_MAX * 2 + 1],
    t_onstack[Q_MAX * 2 + 1],
    scc_rep[Q_MAX * 2 + 1];
unordered_set<int> scc_adj[Q_MAX * 2 + 1];
unordered_set<int> scc_vals[Q_MAX * 2 + 1];
unordered_set<int> scc_downstream[Q_MAX * 2 + 1];
int scc_ind = 1;
vector<int> t_stack;

void strongconnect(int i) {
    t_index[i] = t_lowlink[i] = ind++;
    t_stack.push_back(i);
    t_onstack[i] = true;

    for (auto c: adj[i]) {
        if (!t_index[c]) {
            strongconnect(c);
            UMIN(t_lowlink[i], t_lowlink[c]);
        } else if (t_onstack[c]) {
            UMIN(t_lowlink[i], t_index[c]);
        }
    }

    // if i is a root node, pop the stack and generate an SCC
    if (t_lowlink[i] == t_index[i]) {
        int c;
        do {
            // add c to current strongly connected component
            c = t_stack.back(); t_stack.pop_back();
            t_onstack[c] = false;
            scc_rep[c] = scc_ind;
            if (scc_vals[scc_ind].count((c + Q_MAX) % (Q_MAX))) {
                cout << "-1"; exit(0);
            }
            // to construct condensation graph
            for (auto a: adj[c]) {
                if (scc_rep[a] && scc_rep[a] != scc_ind) {
                    scc_adj[scc_ind].insert(scc_rep[a]);
                    // O(n) merges make this dfs O(n^2) but make later computations easy
                    scc_downstream[scc_ind].insert(ALL(scc_vals[scc_rep[a]]));
                    scc_downstream[scc_ind].insert(ALL(scc_downstream[scc_rep[a]]));
                }
            }
            scc_vals[scc_ind].insert(c);
        } while (c != i);
        // increment count
        scc_ind++;
    }
}

void tarjan() {
    for (int i = 0; i < k; i++) {
        if (!t_index[i])
            strongconnect(i);
    }
    for (int i = Q_MAX; i < k + Q_MAX; i++) {
        if (!t_index[i])
            strongconnect(i);
    }
}

int main() {
    cin >> n >> k;
    // node for each pos, neg in key
    vector<vector<int>> input(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < k; j++) {
           char c; cin >> c;
           // T:0, F:1, X:2
           input[i][j] = (c == 'T' ? 0 : (c == 'F' ? 1 : 2));
       }
    }

    // implication graph:
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (input[j][i] == 2) continue; // student answered X
            if (input[j][i]) { // if we set key to false here && student answered false
                for (int q = 0; q < k; q++) {
                    if (i == q || input[j][q] == 2) continue;
                    if (input[j][q]) { // student ans T, k must be F
                        adj[i].insert(q + Q_MAX);
                    } else { // student ans F, k must be T
                        adj[i].insert(q);
                    }
                }
            } else { // if we set key to true here && student answered true
                for (int q = 0; q < k; q++) {
                    if (i == q || input[j][q] == 2) continue;
                    if (input[j][q]) { // student ans T, k must be F
                        adj[i + Q_MAX].insert(q + Q_MAX);
                    } else { // student ans F, k must be T
                        adj[i + Q_MAX].insert(q);
                    }
                }
            }
        }
    }

    tarjan();

    string ans = string(k, 'F');
    for (int i = 0; i < k; i++) {
        if (scc_downstream[scc_rep[i]].count(i + Q_MAX)) {
            ans[i] = 'T';
            for (auto c: scc_downstream[scc_rep[i + Q_MAX]])
                ans[c % Q_MAX] = (c < Q_MAX) ? 'F' : 'T';
        }
    }
    for (int i = 0; i < k; i++) {
        if (ans[i] == 'T') {
            for (auto c: scc_downstream[scc_rep[i + Q_MAX]])
                ans[c % Q_MAX] = (c < Q_MAX) ? 'F' : 'T';
        } else {
            for (auto c: scc_downstream[scc_rep[i]])
                ans[c % Q_MAX] = (c < Q_MAX) ? 'F' : 'T';
        }
    }
    cout << ans;
}