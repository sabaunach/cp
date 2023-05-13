/* https://vjudge.net/contest/556429#problem/C
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

typedef unsigned long long ull;
int n, K;
int cnt = 0;
map<pair<ull, int>, ull> memo;
ull dfs(string& v, int k = 0) {
    cnt++;
    ull x = stoull(v);
    if (k == K) return x;
    if (memo.count({x,k})) return memo[{x,k}];
    int i = 0, mx_j = -1;
    for (; i < n; i++) { rep(j,i+1,n) {
            if (v[i] < v[j] && v[j] > v[mx_j]) {
                mx_j = j;
            }
        }
        if (mx_j != -1) break;
    }

    ull ans = 0;
    if (mx_j == -1) {
        // swap two identical numbers if available
        rep(j,0,n-1) if (v[j] == v[j+1]) return memo[{x,k}] = dfs(v, k+1);
        // else, swap two smallest
        swap(v[n-2], v[n-1]);
        ans = dfs(v, k+1);
        swap(v[n-2], v[n-1]);
    } else {
        rep(j,i+1,n) {
            if (v[j] == v[mx_j]) {
                swap(v[i], v[j]);
                chmax(ans, dfs(v, k+1));
                swap(v[i], v[j]);
            }
        }
    }
    return memo[{x,k}] = ans;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s >> K;
    n = sz(s);
    cout << dfs(s) << "\n";
    cerr << cnt << "\n";
}