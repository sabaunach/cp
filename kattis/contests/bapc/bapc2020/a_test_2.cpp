#include <bits/stdc++.h>

using namespace std;

int n, m, t=0;
vector<int> a, b;
vector<bool> done;

bool check(int i);

bool sendRight(int i, int d = 0) {
//    for (int j = 0; j < d; j++) cout << " ";
//    cout << "sendRight " << i << "\n";
    if (i+1 == m) {
        if (a[i]+1 < n) {
            a[i]++; t++;
            return true;
        } else return false;
    }
    while (a[i] + 3 >= a[i+1])
        if (!sendRight(i+1, d++)) return false;
    a[i]++; a[i+1]--;
    t++;
    return true;
}

bool sendLeft(int i, int d = 0) {
//    for (int j = 0; j < d; j++) cout << " ";
//    cout << "sendLeft " << i << " (" << a[i] << ")" << "\n";
    if (i == 0) {
        if (a[i] - 1 > 1) {
            a[i]--; t++;
            return true;
        } else return false;
    }
    while (a[i] - 3 <= a[i-1])
        if (!sendLeft(i-1, d++)) return false;
    a[i]--; a[i-1]++;
    t++;
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

    while (true) {
        bool good = true;
        for (int i = 0; i < m; i++) {
            if (a[i] != b[i]) good = false;
            if (!check(i)) return false;
        }
        if (good) return true;
    }
}

int main() {

    cout << (solve() ? to_string(t) : "impossible") << "\n";
}
