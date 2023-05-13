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

int main() {
    /*
     * n    *(n-1)*(n-1)*...
     * (n-1)*(n-2)*(n-2)*...
     *
     */
    ll x = 15*14*14*14;
    rep(i,0,3) {
        cout << x << "\n";
        x %= 1000000007LL;
        x = x*14*13*13*13;
        x %= 1000000007LL;
    }
    cout << x << "\n";
}