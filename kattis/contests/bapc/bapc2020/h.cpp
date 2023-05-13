#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    cout << 3 << "\n";

    auto v2 = v;
    sort(v2.begin(), v2.end());

    unordered_set<int> q;
    vector<pair<int, int>> s;
    for (int i = 0; i < n/4; i++) {
        q.insert(v2[i].second+1);
        q.insert(i+1);
        s.emplace_back(v2[i].first, v2[i].second);
    }
    for (int i = 0; q.size() < n/2; i++) {
        if (!q.count(i+1)) {
            q.insert(i+1);
            s.emplace_back(v[i].first, i);
        }
    }
    for (auto&x: q) cout << x << " "; cout << "\n";
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        v[s[i].second].first = s[i].first;
    }

    q.clear(); s.clear();
    v2 = v;
    sort(v2.begin(), v2.end());
    for (int i = n/4; i < n/2; i++) {
        q.insert(v2[i].second+1);
        q.insert(i+1);
        s.emplace_back(v2[i].first, v2[i].second);
    }
    for (int i = 0; q.size() < n/2; i++) {
        if (!q.count(i+1)) {
            q.insert(i+1);
            s.emplace_back(v[i].first, i);
        }
    }
    for (auto&x: q) cout << x << " "; cout << "\n";
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        v[s[i].second].first = s[i].first;
    }

    for (int i = n/2; i < n; i++) {
        cout << i+1 << " ";
    }
    cout << "\n";
}