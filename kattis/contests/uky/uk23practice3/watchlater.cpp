#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;
int dfs(const string& v, vector<bool>& incl, int x) {
    if (m.count(x)) return m[x];
    if (!x) return 0;
    int mn = INT_MAX;
    for (int c_i = 0; c_i < 26; c_i++) {
        if (x & 1<<c_i) {
            x^=1<<c_i;
            char c = c_i + 'a';
            vector<int> ind;
            char last = ' ';
            int cost = 0;
            for (int i = 0; i < v.size(); i++) {
                if (v[i]==c) {
                    if (last!=c) cost++;
                    ind.push_back(i);
                }
                if (incl[i]) last=v[i];
                if (v[i]==c) incl[i]=false;
            }
            // cout << x << ": " << (char)(c_i+'a') << " " << cost << endl;
            mn = min(mn, cost + dfs(v,incl,x));
            for (auto i: ind) {
                incl[i] = true;
            }
            x^=1<<c_i;
        }
    }
    return m[x] = mn;
}

int main() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int x = 0;
    for (auto c: s) x |= 1<<(c-'a');
    vector<bool> incl(n);
    cout << dfs(s,incl,x);
}