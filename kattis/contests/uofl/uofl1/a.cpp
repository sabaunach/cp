#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k, n;
    cin >> k >> n;

    vector<int> v;
    ull total = 0;
    for (int i = 0; i <  n; i++) {
        int in; cin >> in;
        total += in;
        v.push_back(in);
    }
    if (total % k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    ull target = total / k;
    ull l = 0, r = 0, sum = v[0];
    unordered_map<ull, ull> end_start;
    for (; l < v.size();) {
        if (l == r && v[l] > target) {
            cout << "NO" << endl;
            return 0;
        }
        if (sum < target) {
            r++;
            sum += v[r % n];
        }
        else if (sum > target) {
            sum -= v[l];
            l++;
        }
        else if (sum == target) {
            if (end_start.count(l - 1)) {
                end_start[r % n] = end_start[l - 1];
                if ((r + 1) % n == end_start[r % n]) {
                    cout << "YES" << endl;
                    return 0;
                }
            } else {
                end_start[r % n] = l;
            }
            sum -= v[l];
            l++;
        }
    }
    cout << "NO" << endl;
}