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

vector<int> primes, fac;
ll N = 1e8;
ll ans = 0;
void dfs(vector<int>& v, vector<int>& p, vector<vector<int>>& p_st, ll n, int i) {
    if (n > N) return;

    if (v[i]==1) {
        p_st.pub(p);
    }

    p = vector<int>(p_st.back().begin(), p_st.back().end());
    int cur = 1;
    if (i > 0) {
        for (int j = p.size()-1; j > 0; j--) {
            for (int w = 1; w <= v[i] && j-w >= 0; w++) {
                p[j] += p[j-w];
            }
            chmax(cur, p[j]);
        }
    }
    ans += cur;
//    cout << n << ": (" << primes[i] << ") ";
//    rep(x,0,5) cout << p[x] << " "; cout << "\n";

    rep(j,max(i,1),sz(primes)) {
        if (n*primes[j] > N) break;
        v[j]++;
        dfs(v,p,p_st,n*primes[j],j);
        v[j]--;
    }

    p = vector<int>(p_st.back().begin(), p_st.back().end());
    for (int j = p.size()-1; j > 0; j--) {
        for (int w = 1; w <= v[i]-1 && j-w >= 0; w++) {
            p[j] += p[j-w];
        }
    }
    if (v[i] == 1) { p_st.pop_back(); }
}

int main() {
    fac.resize(N+1);
    fac[0] = fac[1] = 0;
    primes.pub(1);
    rep(i,2,N) {
        if (!fac[i]) {
            primes.pub(i);
            for(int j = i+i; j <= N; j+=i)
                fac[j] = i;
        }
    }
    vector<int> v(sz(primes)), p(28);
    vector<vector<int>> p_st;
    v[0] = 1;
    p[0] = 1;
    cout << "hi" << endl;
    dfs(v, p, p_st, 1, 0);
    cout << ans << "\n";
}