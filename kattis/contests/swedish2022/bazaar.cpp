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

#define all(x) bg(x), end(x)
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define pub push_back

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
    int n; cin >> n;
    /*
     * 1 3 3 6 | 2 4 4 6
     *       6 |       1
     * 2       | 3
     *   4     |   5
     *     5   |     1
     *
     * 1 3 3 6 | 2 4 4 6
     *       6 |
     * 2       | 3
     *   4     |   5
     *     5   |     1
     */
    /*
     * take action that maximizes A-B (or minimizes) at every step?
     * take action that maximizes A-B of remaining stuff?
     * 1 2 | 3 4 (A wants to maximize, B minimize)
     *
     *
     */
}