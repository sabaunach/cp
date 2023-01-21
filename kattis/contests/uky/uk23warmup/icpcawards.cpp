#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<string> s;
    vector<pair<string, string>> v;
    int cnt = 0;
    while (n--) {
        string uni, team; cin >> uni >> team;
        if (s.insert(uni).second && cnt++ < 12) {
            cout << uni << " " << team << endl;
        }
    }
}
