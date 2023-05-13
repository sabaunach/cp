#include <bits/stdc++.h>

using namespace std;

int n, m, t=0;
const int N = 1001;
vector<int> a, b;
vector<bool> done;
set<int> to_process;
vector<bool> on_queue;
unordered_set<bitset<N>> seen;

bool sendRight(int i, int d = 0) {
//    for (int j = 0; j < d; j++) cout << " ";
//    cout << "sendRight " << i << " (" << a[i] << ")" << endl;
    t++;
    if (i+1 == m) {
        if (a[i]+1 < n) {
            a[i]++; t++;
            if (a[i] != b[i] && !on_queue[i]) to_process.insert(i), on_queue[i] = 1;
            else if (a[i] == b[i] && on_queue[i]) to_process.erase(i), on_queue[i] = 0;
            return true;
        } else return false;
    }
    while (a[i] + 3 >= a[i+1])
        if (!sendRight(i+1, ++d)) return false;
    a[i]++; a[i+1]--;
    if (a[i] != b[i] && !on_queue[i]) to_process.insert(i), on_queue[i] = 1;
    else if (a[i] == b[i] && on_queue[i]) to_process.erase(i), on_queue[i] = 0;
    if (a[i+1] != b[i+1] && !on_queue[i+1]) to_process.insert(i+1), on_queue[i+1] = 1;
    else if (a[i+1] == b[i+1] && on_queue[i+1]) to_process.erase(i+1), on_queue[i+1] = 0;

    bitset<N> bs;
    for (auto x: a) bs.set(x);
    if (!(seen.insert(bs).second)) return false;

    return true;
}

bool sendLeft(int i, int d = 0) {
//    for (int j = 0; j < d; j++) cout << " ";
//    cout << "sendLeft " << i << " (" << a[i] << ")" << endl;
    t++;
    if (i == 0) {
        if (a[i] - 1 > 1) {
            a[i]--;
            if (a[i] != b[i] && !on_queue[i]) to_process.insert(i), on_queue[i] = 1;
            else if (a[i] == b[i] && on_queue[i]) to_process.erase(i), on_queue[i] = 0;
            return true;
        } else return false;
    }
    while (a[i] - 3 <= a[i-1])
        if (!sendLeft(i-1, ++d)) return false;
    a[i]--; a[i-1]++;
    if (a[i] != b[i] && !on_queue[i]) to_process.insert(i), on_queue[i] = 1;
    else if (a[i] == b[i] && on_queue[i]) to_process.erase(i), on_queue[i] = 0;
    if (a[i-1] != b[i-1] && !on_queue[i-1]) to_process.insert(i-1), on_queue[i-1] = 1;
    else if (a[i-1] == b[i-1] && on_queue[i-1]) to_process.erase(i-1), on_queue[i-1] = 0;

    bitset<N> bs;
    for (auto x: a) bs.set(x);
    if (!(seen.insert(bs).second)) return false;

    return true;
}


bool check(int i) {
    if (a[i] == b[i]) return true;
    else if (a[i] < b[i]) return sendRight(i);
    else return sendLeft(i);
}

bool solve() {
    cin >> n >> m;
    a.resize(m); b.resize(m);
    done.resize(m);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    bitset<N> bs;
    for (auto x: a) bs.set(x);
    seen.insert(bs);

    on_queue.resize(m);
    for (int i = 0; i < m; i++) if (a[i] != b[i]) {
            to_process.insert(i);
            on_queue[i] = 1;
        }
    while (!to_process.empty()) {
        auto top = *to_process.begin(); to_process.erase(to_process.begin());
        on_queue[top] = false;
        if (!check(top)) return false;
    }
    return t;
}

int main() {

    cout << (solve() ? to_string(t) : "impossible") << "\n";
}