#include <bits/stdc++.h>

using namespace std;

int n, m, t=0;
vector<int> a, b;
vector<bool> done;
set<int> to_process;
vector<bool> on_queue;
vector<bool> sent_right, sent_left;

bool check(int i);

bool sendRight(int i, int d = 0) {
//    for (int j = 0; j < d; j++) cout << " ";
//    cout << "sendRight " << i << "\n";
    if (i+1 == m) {
        if (a[i]+1 < n) {
            a[i]++; t++;
            if (a[i] != b[i] && !on_queue[i]) to_process.insert(i), on_queue[i] = 1;
            else if (a[i] == b[i] && on_queue[i]) to_process.erase(i), on_queue[i] = 0;
            return true;
        } else return false;
    }
    while (a[i] + 3 >= a[i+1])
        if (!sendRight(i+1, d++)) return false;
    a[i]++; a[i+1]--;
    if (a[i] != b[i] && !on_queue[i]) to_process.insert(i), on_queue[i] = 1;
    else if (a[i] == b[i] && on_queue[i]) to_process.erase(i), on_queue[i] = 0;
    if (a[i+1] != b[i+1] && !on_queue[i+1]) to_process.insert(i+1), on_queue[i+1] = 1;
    else if (a[i+1] == b[i+1] && on_queue[i+1]) to_process.erase(i+1), on_queue[i+1] = 0;
    t++;
    return true;
}

bool sendLeft(int i, int d = 0) {
//    for (int j = 0; j < d; j++) cout << " ";
//    cout << "sendLeft " << i << " (" << a[i] << ")" << "\n";
    if (i == 0) {
        if (a[i] - 1 > 1) {
            a[i]--; t++;
            if (a[i] != b[i] && !on_queue[i]) to_process.insert(i), on_queue[i] = 1;
            else if (a[i] == b[i] && on_queue[i]) to_process.erase(i), on_queue[i] = 0;
            return true;
        } else return false;
    }
    while (a[i] - 3 <= a[i-1])
        if (!sendLeft(i-1, d++)) return false;
    a[i]--; a[i-1]++;
    if (a[i] != b[i] && !on_queue[i]) to_process.insert(i), on_queue[i] = 1;
    else if (a[i] == b[i] && on_queue[i]) to_process.erase(i), on_queue[i] = 0;
    if (a[i-1] != b[i-1] && !on_queue[i-1]) to_process.insert(i-1), on_queue[i-1] = 1;
    else if (a[i-1] == b[i-1] && on_queue[i-1]) to_process.erase(i-1), on_queue[i-1] = 0;
    t++;
    return true;
}

bool check(int i) {
    if (a[i] == b[i]) return true;
    else if (a[i] < b[i]) {
        if (sent_left[i]) return false;
        sent_right[i] = true;
        return sendRight(i);
    }
    if (sent_right[i]) return false;
    sent_left[i] = true;
    return sendLeft(i);
}

bool solve() {
    cin >> n >> m;
    a.resize(m); b.resize(m);
    done.resize(m);
    sent_right.resize(m); sent_left.resize(m);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

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