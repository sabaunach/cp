#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second


int main() {
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &r: v) for (auto &x: r) cin >> x;
    cin.ignore(1000, '\n');
    string s; getline(cin, s);
    s += string((n - (s.size() % n)) % n, ' ');
    vector<vector<int>> t(s.size()/n);
    for (int i = 0; i < t.size(); i++) {
        for (int j = i*n; j < i*n+n; j++) {
            int x;
            if ('A' <= s[j] && s[j] <= 'Z')
                x = s[j]-'A';
            else if ('0' <= s[j] && s[j] <= '9')
                x = s[j]-'0'+26;
            else x = 36;
            t[i].push_back(x);
        }
    }
    for (int i = 0; i < t.size(); i++) {
        vector<int> u(n);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                (u[j] += t[i][k]*v[j][k]) %= 37;
            }
        }
        t[i] = u;
    }
    string res;
    for (auto &r: t) {
        for (auto &x: r) {
            if (x <= 25) cout << (char)(x + 'A');
            else if (x <= 35) cout << (char)(x + '0' - 26);
            else cout << ' ';
        }
    }

}