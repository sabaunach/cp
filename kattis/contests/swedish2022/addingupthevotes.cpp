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

void solve() {
    int n; cin >> n;
    vector<int> repr(n);
    rep(i,0,n) repr[i] = i+1;
    cout << "? ";
    rep(i,1,n+1) cout << (i % (n)) + 1 << " ";
    cout << flush;
    string s; cin >> s;
    rep(i,0,n) if(s[i]=='1') repr[i] = repr[(i+1)%n] = min(repr[i], repr[(i+1)%n]);
    vector<int> roots;
    rep(i,0,n) if(repr[i]==i+1) roots.push_back(i+1);
    int j = 0;
    vector<int> query(n);
    cout << "? ";
    rep(i,0,n) {
        query[i] = roots[(j=(j+1)%roots.size())];
        cout << query[i] << " ";
    }
    cout << flush;
    cin >> s;
    rep(i,0,n) if(s[i]=='1') repr[i] = repr[query[i]-1] = min(repr[i], repr[query[i]-1]);
    unordered_map<int, int> freq;
    rep(i,0,n) freq[repr[i]]++;
    for (auto&[k,v]: freq) if (v > n/2) {
        cout << "! " << k << flush;
        return;
    }
    cout << "! -1" << flush;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
}