#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int int_fast32_t
#define ll int_fast64_t
#define ull uint_fast64_t
#define uint uint_fast32_t
#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)
#define ALL(a) (a).begin(), (a).end()
#define umap unordered_map
#define uset unordered_set
#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define pbds __gnu_pbds
typedef pbds::trie<string, pbds::null_type, pbds::trie_string_access_traits<>, pbds::pat_trie_tag,
pbds::trie_prefix_search_node_update> trie;
typedef pbds::tree<int,pbds::null_type,less<>,pbds::rb_tree_tag,pbds::tree_order_statistics_node_update> ordered_set;

const int d4i[4] = {-1, 0, 1, 0},
d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct pt {
    ll x, y;
    pt() {}
    pt(ll _x, ll _y) : x(_x), y(_y) {}
    pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
    ll cross(const pt &p) const { return x * p.y - y * p.x; }
    ll dot(const pt &p) const { return x * p.x + y * p.y; }
    ll cross(const pt &a, const pt &b) const { return (a - *this).cross(b - *this); }
    ll dot(const pt &a, const pt &b) const { return (a - *this).dot(b - *this); }
    ll sqrLen() const { return this->dot(*this); }
};

void solve() {

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}
