#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int C = 3;
    vector<int> v(N);
    vector<int> cnt(C);
    for (int i = 0; i < N; i++) {
        char in; cin >> in;
        v[i] = in - 'A';
        cnt[in - 'A']++;
    }

    vector<int> perm(C);
    for (int i = 0; i < C; i++) perm[i] = i;

    int res = 9999999;

    do {
        int i = 0;
        int cur = 0;
        for (int c = 0; c < C; c++) {
            int cx = perm[c];
            for (int j = 0; j < cnt[cx]; j++) {
                if (v[i + j] != cx) {
                    cur++;
                }
            }
            i += cnt[cx];
        }
        res = min(res, cur);
        // try the shifts
        for (int o = 1; o < N; o++) {
            i = 0;
            for (int c = 0; c < C; c++) {
                // remove o-1 from cur group, add to prev group
                int val = v[(i + o - 1) % N];
                if (val == perm[c]) cur++;
                else if (val == perm[(c - 1 + C) % C]) cur--;
                i += cnt[perm[c]];
            }
            res = min(res, cur);
        }

    } while (next_permutation(perm.begin() + 1, perm.end()));

    cout << res << endl;
}