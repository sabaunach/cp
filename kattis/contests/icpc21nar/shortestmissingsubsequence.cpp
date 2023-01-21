#include <bits/stdc++.h>

using namespace std;

int precomp[1000001][26];
string s;
int min_l = 1;

int solve() {
    string q; cin >> q;
    if (q.size() != min_l) return 0;
    int i = s.size();
    for (int j = q.size() - 1; j >= 0; j--) {
        i = precomp[i][q[j] - 'a'];
        if (i == -1) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    unordered_set<char> v;
    string vin; cin >> vin;
    for (auto c: vin) v.insert(c);
    cin >> s;
    int n; cin >> n;

    int l[26];
    memset(l, -1, sizeof(l));
    for (int i = 0; i <= s.size(); i++) {
        memcpy(precomp[i], l, sizeof(l));
        l[s[i] - 'a'] = i;
    }
    unordered_set<char> seen;
    for (int i = s.size() - 1; i >= 0; i--) {
        seen.insert(s[i]);
        if (seen.size() == v.size()) {
            seen.clear();
            min_l++;
        }
    }

    while (n--) {
        cout << solve() << endl;
    }

};