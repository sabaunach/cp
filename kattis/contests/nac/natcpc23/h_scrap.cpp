/* https://vjudge.net/contest/556429#problem/H
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back

#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define sz(x) int((x).size())

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef vector<int> vi;


int test(int n, int c) {

    vector<int> v(n);

    rep(i,0,n) v[i] = (rand() % 10) * 10 + (rand() % 10) + 1;

    sort(all(v)); reverse(all(v));

    int sm = accumulate(all(v), 0);
    int j = -1;
    rep(i,0,c) {
        sm -= v[i];
        if (v[0] > sm/c + (bool)(sm%c)) { j = i; break; }
    }



    priority_queue<int> pq; fore(x, v) pq.push(x);
    int cnt = 0;
    while (!pq.empty()) {
        vector<int> to_push;
        cnt++;
        rep(i,0,c) {
            if (pq.empty()) break;
            int top = pq.top(); pq.pop();
            if (top == 1) continue;
            to_push.push_back(top-1);
        }
        fore(x, to_push) pq.push(x);
    }

    assert(cnt == max(v[0], accumulate(all(v), 0)/c + (bool)(accumulate(all(v), 0)%c)));
    if (cnt != accumulate(all(v), 0)/c + (bool)(accumulate(all(v), 0)%c)) {
        cout << "Assertion failed" << endl;
        if (cnt != v[0]) {
            cout << "Assertion failed x2" << endl;

            fore(x, v) cout << x << " "; cout << endl;
            if (j == -1) {
                cout << "Balanced" << endl;
            } else {
                cout << "Unbalanced" << endl;
            }
            cout << "Balanced: " << accumulate(all(v), 0)/c + (bool)(accumulate(all(v), 0)%c) << endl;

            cout << "Unbalanced: " << v[0] << endl;
            cout << cnt << endl;

            string s;
            cin >> s;
        }
    }
}

int main() {
//    cin.tie(nullptr); cout.tie(nullptr);
//    ios_base::sync_with_stdio(false);
    srand(time(NULL));

//    cout << ((__uint128_t)LLONG_MAX*LLONG_MAX <= (__uint128_t)LLONG_MAX*(LLONG_MAX-1));
//    exit(0);

    int n,c; cin >> n >> c;

    while (true) test(n, c);

}
