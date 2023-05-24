#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define bg begin
#define all(x) bg(x), end(x)
#define sor(x) sort(all(x))
#define sz(x) int(x.size())
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define fore(a,x) for (auto& a: x)

#define tcT template<class T
#define tcTU tcT, class U
tcT> using v = vector<T>;
tcTU> using pr = pair<T, U>;
tcTU> using umap = unordered_map<T, U>;
tcTU> using uset = unordered_map<T, U>;

tcT> bool chmin(T& a, T& b) { return b < a ? a = b, b : a; }
tcT> bool chmax(T& a, T& b) { return a < b ? a = b, b : a; }

typedef long long ll;
typedef long double db;
typedef pr<int, int> pii;
typedef v<int> vi;
typedef v<ll> vl;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}
