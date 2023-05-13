/* https://vjudge.net/contest/556429#problem/A
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


vector<bitset<500>> vbs;
unordered_map<bitset<500>, int> memo;
int n;
int dfs(bitset<500> st) {
    if (memo.count(st)) return memo[st];
    int mx = 1;
    bitset<500> mask; mask.flip(); int prev_i = 0;
    rep(i,0,n) if (st.test(i)) {
            mask <<= (i - prev_i);
            prev_i = i;
            chmax(mx, 1 + dfs(st & mask & vbs[i]));
        }
    return memo[st] = mx;
}


int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<string> v(n); fore(x, v) cin >> x;

//    string s = "abcdef";
//    vector<string> perms(n);
//    do {
//        perms.pub(s);
//    } while (next_permutation(s.begin(), s.end()));
//    n = 50;
//    vector<string> v; vector<bool> chosen(perms.size());
//    srand(time(NULL));
//    while (v.size() < n) {
//        int x = rand() % perms.size();
//        if (chosen[x]) continue;
//        chosen[x] = true;
//        v.pub(perms[x]);
//    }

    int e = 0; size_t mx_deg = 0, mn_deg = n; vector<unordered_set<int>> adj_inv(n); rep(i,0,n) rep(j,0,n) if (i != j) adj_inv[i].insert(j);
    vbs.resize(n);
    vector<vector<int>> adj(n);
    rep(i,0,n) rep(j,i+1,n) {
            int cnt = 0;
            rep(c,0,v[i].size()) if (v[i][c] != v[j][c]) cnt++;
            if (cnt > 2) {
                vbs[i].set(j); vbs[j].set(i);
                adj[i].pub(j); adj[j].pub(i); e++;
            }
        }
    rep(i,0,n) cout << v[i] << "\n";
    rep(i,0,n) {
        chmax(mx_deg, adj[i].size()); chmin(mn_deg, adj[i].size());
        fore(x, adj[i]) {
            adj_inv[i].erase(x);
            // cout << v[i] << " " << v[x] << "\n";
        }
    }
    rep(i,0,n) {
        fore(x, adj_inv[i]) {
            cout << v[i] << " " << v[x] << "\n";
        }
    }

    vector<int> col(n);
    function<void(int, int, pair<int,int>&)> twocol;
    twocol = [&] (int i, int c, pair<int,int>& p) {
        if (col[i]) return;
        col[i] = c; if (c == 1) p.fi++; else p.se++;
        fore(x, adj_inv[i]) twocol(x, c == 1 ? 2 : 1, p);
    };
    bool good = true;
    vector<pair<int, int>> cc;
    int ans2 = 0;
    rep(i,0,n) if (!col[i]) {
        cc.push_back({0,0});
        twocol(i,1,cc.back());
        ans2 += max(cc.back().fi, cc.back().se);
    }
    int ans = 0;
    bitset<500> mask; mask.flip();
    rep(i,0,n) {
        chmax(ans, dfs(vbs[i] & mask));
        mask <<= 1;
    }
    int a = 0, b = 0;
    rep(i,0,n) if (col[i] == 1) a++;
    cerr << ans << "\n";
    cerr << ans2 << "\n";
    cerr << memo.size() << "\n";
    cerr << e << "\n";
    cerr << (double)e/((n*(n-1))/2) << "\n";
    cerr << mn_deg << " " << mx_deg << "\n";
}