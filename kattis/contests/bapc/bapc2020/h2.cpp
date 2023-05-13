#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }
    cout << 3 << "\n";

    vector<pair<int, int>> v2(n);
    for (int i = 0; i < n; i++) v2[i] = {v[i], i};
    sort(v2.begin(), v2.end());

    unordered_set<int> q;
    for (int i = 0; i < n && q.size() + 1 < n/2; i++) {
        q.insert(v2[i].first);
        q.insert(v2[i].second);
    }
    for (int i = 0; q.size() < n/2; i++) {
        q.insert(i);
    }
    for (auto&x: q) cout << x+1 << " "; cout << endl;
    vector<int> s, inds;
    for (auto it = q.begin(); it != q.end(); it++) {
        s.push_back(v[*it]);
        inds.push_back(*it);
    }

    sort(s.begin(), s.end());
    sort(inds.begin(), inds.end());

    for (int i = 0; i < s.size(); i++) {
        v[inds[i]] = s[i];
    }

    for (int i = 0; i < n; i++) v2[i] = {v[i], i};
    sort(v2.begin(), v2.end());

    q.clear();
    for (int i = n/4; i < n && q.size() + 1 < n/2; i++) {
        q.insert(v2[i].first);
        q.insert(v2[i].second);
    }
    for (int i = 0; q.size() < n/2; i++) {
        q.insert(i);
    }
    for (auto&x: q) cout << x+1 << " "; cout << endl;

    for (int i = n/2+1; i <= n; i++) cout << i << " ";
    cout << "\n";
}