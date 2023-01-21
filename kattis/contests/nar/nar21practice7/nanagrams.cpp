#include <bits/stdc++.h>

typedef unsigned long long ull;
ull MOD = 1000000007;

using namespace std;

string tostr(ull num) {
    if (num == 0) return "1000000000";
    string s(10, '0');
    while (num > 0) {
        s[num % 10] += 1;
        num /= 10;
    }
    return s;
}

int len(string s) {
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        cnt += s[i] - '0';
    }
    return cnt;
}

struct node {
    ull paths = 0;
    int max_l = 0;
    int cnt = 0;
};

node dfs(string & s, unordered_map<string, node> & m) {
    auto cur = m[s];
    if (cur.max_l != 0) // already visited
        return cur;
    for (int i = 0; i < 10; i++) {
        s[i]++;
        if (m.count(s)) {
            auto child = dfs(s, m);
            if (child.max_l > cur.max_l) {
                cur.max_l = child.max_l;
                cur.paths = 0;
            }
            if (child.max_l == cur.max_l) {
                cur.paths = (cur.paths + (child.paths * cur.cnt) % MOD);
            }
        }
        s[i]--;
    }
    if (cur.max_l == 0) {  // cur is leaf
        cur.max_l = len(s);
        cur.paths = cur.cnt;
    }
    return m[s] = cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ull n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;

    set<ull> nums_set;
    for (int x = d, i = 0; i < n; i++) {
        nums_set.insert(x);
        x = (a * x + b) % c;
    }
    unordered_map<string, node> nums_map;
    unordered_set<string> keys_set;

    for (auto x: nums_set) {
        nums_map[tostr(x)].cnt++;
        keys_set.insert(tostr(x));
    }

    for (auto k: keys_set) {
        dfs(k, nums_map);
    }

    while (m--) {
        int q; cin >> q;
        auto node = nums_map[tostr(q)];
        cout << (max((int) node.paths / node.cnt , 1) % MOD) << endl;
    }
}
