#include <bits/stdc++.h>

using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define se second
#define fi first
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    vector<int> p(N), c(N);
    vector<pair<int, int>> go_eq(N);
    for (int i = 0 ; i < N; i++) {
        cin >> p[i] >> c[i];
        go_eq[i] = {1 + ((c[i] - 1) / p[i]), i};
    }

    sort(ALL(go_eq));
    long long day = 0, daily = 0, borrow = 0;
    for (int i = 0; i < N; i++) {
        // get to current day
        day = go_eq[i].fi;
        if (daily * day - borrow >= M) {
            // backtrack
            cout << 1 + ((M + borrow - 1) / daily) << endl;
            return 0;
        }
        int j = go_eq[i].se;
        // invest in next option
        borrow += c[j];
        daily += p[j];
    }
    cout << 1 + ((M + borrow - 1) / daily) << endl;
    return 0;
}
