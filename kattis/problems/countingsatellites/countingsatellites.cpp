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

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

template<class T> bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
    ll k; cin >> k;

    // compute sequence of numbers to use to generate strings
    string t = "SATELLITE";
    vector<vector<int>> pos(26);
    rep(i,0,sz(t)) {
        pos[t[i]-'A'].pub(i);
    }
    fore(v, pos) reverse(all(v));

    vector<ll> cnt(sz(t)+1);
    vector<ll> seq;
    cnt[0] = 1;
    bool good = true;
    for (int l = 1; good; l++) {
        fore(c, t) {
            fore(i, pos[c-'A']) {
                // will overflow
                if (cnt[i + 1] > LLONG_MAX - cnt[i]) {good = false; break; };
                cnt[i + 1] += cnt[i];
            }
            if (!good) break;
        }
        if (!good) break;
        seq.pub(cnt[sz(t)]);
    }

    vector<int> v;
    // representing k using seq: find most significant digit
    int i = prev(ub(all(seq), k)) - bg(seq); k -= seq[i];
    // from here on, whenever we add an S at some point in the string SATTELITE*i,
    // we get seq[i] - seq[i-1] new strings. adjust seq accordingly
    for (int j = sz(seq)-1; j > 0; j--) seq[j] -= seq[j-1];
    // and represent k using seq
    for (; i >= 0; i--) {
        v.pub(k/seq[i]); k-=(seq[i]*(k/seq[i]));
    }

    // output
    string res = "";
    fore(x, v) {
        res += string(x, 'S');
        res += t;
    }
    cout << res << "\n";
}