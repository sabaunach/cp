#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

#define tcT template<class T
#define tcTU tcT, class U
tcT> using v = vector<T>;
tcTU> using pr = pair<T, U>;

typedef long long ll;
typedef pr<int, int> pii;
typedef v<int> vi;
tcT> bool chmin(T& a, T& b) { return b < a ? a = b, b : a; }
tcT> bool chmax(T& a, T& b) { return a < b ? a = b, b : a; }

tcTU> T fstTrue(T lo, T hi, U f) {
    hi++;
    while (lo < hi) {
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo--;
    while (lo < hi) {
        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    }
    return lo;
}

tcTU> ostream& operator<<(ostream& s, pr<T, U>& p) {
    s << "{" << p.fi << ", " << p.se << "}"; return s;
}
tcTU> istream& operator>>(istream& s, pr<T, U>& p) {
    s >> p.fi >> p.se; return s;
}
#define zz(t, v, c) c> ostream& operator<<(ostream& s, t<v>& d) {\
    fore(x, d) s << x << " "; return s; }\
    c> istream& operator>>(istream& s, t<v>& d) {\
    fore(x, d) s >> x; return s; }
#define TU T, U
zz(v, T, tcT) zz(list, T, tcT)
zz(map, TU, tcTU) zz(unordered_map, TU, tcTU)
zz(set, T, tcT) zz(unordered_set, T, tcT)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
tcT> using Ordered_multiset = tree<T, null_type,
 less_equal<T>, rb_tree_tag,
 tree_order_statistics_node_update>;
tcT> using Ordered_set = tree<T, null_type,
 less<T>, rb_tree_tag, tree_order_statistics_node_update>;
tcT> using Trie = trie<T, null_type, 
trie_string_access_traits<>, pat_trie_tag,
trie_prefix_search_node_update>;
// #include <ext/pb_ds/priority_queue.hpp> // Pairing heap
// __gnu_pbds::priority_queue<int> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}
