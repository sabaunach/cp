#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define fi first
#define se second

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)
#define ALL(a) (a).begin(), (a).end()

#define umap unordered_map
#define uset unordered_set
#define pbds __gnu_pbds

//typedef pbds::trie<string, pbds::null_type, pbds::trie_string_access_traits<>,
//    pbds::pat_trie_tag, pbds::trie_prefix_search_node_update> trie;
//typedef pbds::tree<int, pbds::null_type, less<>, pbds::rb_tree_tag,
//    pbds::tree_order_statistics_node_update> ordered_set;

const int d4i[4] = {-1, 0, 1, 0},
d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct pt {
    ll x, y; pt() {} pt(ll x, ll y) : x(x), y(y) {}
    pt operator+(const pt &p) const { return {x + p.x, y + p.y}; }
    pt operator-(const pt &p) const { return {x - p.x, y - p.y}; }
    ll cross(const pt &p) const { return x * p.y - y * p.x; }
    ll dot(const pt &p) const { return x * p.x + y * p.y; }
    ll sqrLen() const { return this->dot(*this); }
    // relative to the pt that is called upon
    ll cross(const pt &a, const pt &b) const { return (a - *this).cross(b - *this); }
    ll dot(const pt &a, const pt &b) const { return (a - *this).dot(b - *this); }
};
ostream & operator<<(ostream & s, const pt & p) { return s << ("(" + to_string(p.x) + ", " + to_string(p.y) + ")"); }

struct frac {
    ll n = 1, d = 1; frac(ll n, ll d) : n(n), d(d) {}
    static frac simplify(const frac &a) { ll g = gcd(a.n, a.d); return {a.n / g, a.d / g}; }
    frac operator+(const frac &a) const { ll l = lcm(d, a.d); return simplify({n * (l / d) + a.n * (l / a.d), l}); }
    frac operator*(const frac &a) const { return simplify({n * a.n, d * a.d}); }
    frac operator-(const frac &a) const { return *this + frac(-1*a.n, a.d);  }
    frac operator/(const frac &a) const { if (a.n == 0) throw runtime_error("divide by 0"); return *this * frac(a.d, a.n); }
    [[nodiscard]] double val() const { return (double)n / (double)d; }
};
ostream & operator<<(ostream & s, const frac & a) { return s << (to_string(a.n) + "/" + to_string(a.d)); }

struct trie {
    const static char o = 'A';
    trie* v[26]; bool is_key;
    trie() : is_key(false) {}

    void insert(const string& word) {
        trie * curr = this;
        for (char c: word) {
            if (!curr->v[c-o]) curr->v[c-o] = new trie();
            curr = curr->v[c-o];
        }
        curr->is_key = true;
    }

    bool search(const string& word) {
        trie * curr = this;
        for (char c: word) {
            if (!curr->v[c-o]) return false;
            curr = curr->v[c-o];
        }
        return curr->is_key;
    }

    bool startsWith(const string& prefix) {
        trie * curr = this;
        for (char c : prefix) {
            if (!curr->v[c-o]) return false;
            curr = curr->v[c-o];
        }
        return true;
    }
};

void solve() {

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}
