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

// s = text / gamma
// t = target / alpha
ll solve(string s, string t) {
    // character (A-Z): positions in t
    vector<vector<int>> pos(26);
    rep(i,0,sz(t)) {
        pos[t[i]-'A'].pub(i);
    }
    // reverse so that when we iterate over positions for updates,
    // we do not over-count for adjacent characters
    fore(v, pos) reverse(all(v));

    // counts of current prefixes of t we have seen up to this point
    // cnt[0] = 1, for base case: beginning of a new subsequence
    vector<ll> cnt(sz(t)+1);
    cnt[0] = 1;
    fore(c, s)
        fore(i, pos[c-'A'])
            cnt[i+1] += cnt[i];

    return cnt[sz(t)];
}


int main() {
    string t = "SATELLITE";
    string s = "";
    cout << solve(s, t) << "\n";
//    int mx = 3000/t.size();
//    rep(k,1,mx) {
//        cout << k << ": " << solve(s, t) << "\n";
//        s = t + s;
//    }
}