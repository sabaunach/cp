#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;

    for (int t = 1; cin >> n; t++) {
        set<int> s;
        for (int i = 0; i < n; i++) {
            int in; cin >> in;
            s.insert(in);
        }
        vector<int> v;
        for (auto num: s) {
            v.push_back(num);
        }
        int m; cin >> m;
        cout << "Case " << t << ":" << endl;
        while (m--) {
            int q; cin >> q;
            int l = 0, r = v.size() - 1;
            int sum = v[l] + v[r];
            while (l < r) {
                int tempsum = v[l] + v[r];
                sum = (abs(q - tempsum) < abs(q - sum)) ? tempsum : sum;
                if (tempsum < q) l++;
                else if (tempsum > q) r--;
                else break;
            }
            cout << "Closest sum to " << q << " is " << sum << "." << endl;
        }
    }
}