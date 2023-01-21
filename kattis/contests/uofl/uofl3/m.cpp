#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    list<char> l;
    unordered_map<char, int> m;
    unordered_map<char, char> a = {{'R', 'S'}, {'B', 'K'}, {'L', 'H'}};
    for (char c; cin >> c;) {
        if (l.size() < 3) {
            l.push_back(c);
            m[c]++;
        }
        if (l.size() < 3) continue;
        if (m.size() == 3) {
            cout << 'C';
            l.clear();
            m.clear();
        } else {
            // remove from front, push to back on next iter
            char f = l.front();
            m[f]--;
            if (m[f] <= 0) m.erase(f);
            cout << a[f];
            l.pop_front();
        }
    }
    // empty the deque
    while (!l.empty()) {
        char f = l.front();
        cout << a[f];
        l.pop_front();
    }
}