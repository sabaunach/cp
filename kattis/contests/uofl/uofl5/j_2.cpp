#include <bits/stdc++.h>

using namespace std;

double ev[200000];
bool vis[200000];
pair<double, double> prs[200000];
pair<int, int> nxt[200000];
unordered_set<int> starts;

double dfs(int s) {
    if (vis[s]) return ev[s];
    vis[s] = true;
    return ev[s] = prs[s].first * dfs(nxt[s].first) + prs[s].second * dfs(nxt[s].second);
}

int main() {
    int l, p; cin >> l >> p;
    for (int i = 0; i < l + p; i++) starts.insert(i);
    for (int i = 0; i < l; i++) {
        cin >> ev[i];
        vis[i] = true;
        cerr << i << ": " << ev[i] << endl;
    }
    for (int i = l; i < l + p; i++) {
        cin >> prs[i].first >> prs[i].second;
        double tot = prs[i].first + prs[i].second;
        prs[i].first /= tot;
        prs[i].second /= tot;

        cin >> nxt[i].first >> nxt[i].second;
        nxt[i].first -= 1; nxt[i].second -= 1;
        starts.erase(nxt[i].first); starts.erase(nxt[i].second);

        cerr << i << ": " << prs[i].first << " " << prs[i].second << " " << nxt[i].first << " " << nxt[i].second << endl;
    }

    double best = -1;
    for (auto s: starts) {
        cerr << "start: " << s;
        best = max(best, dfs(s));
        cerr << " => " << setprecision(100) << ev[s] << endl;
    }
    for (int i = 0; i < l + p; i++) {
        cerr << i << ": " << ev[i] << endl;
    }
    cout << setprecision(100) << best;
}