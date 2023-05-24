#include "template.cpp"

tcTU> ostream& operator<<(ostream& s, pr<T, U>& p) {
    s << "{" << p.fi << ", " << p.se << "}"; return s; }
tcTU> istream& operator>>(istream& s, pr<T, U>& p) {
    s >> p.fi >> p.se; return s; }
#define zz(t, v, c)\
    c> ostream& operator<<(ostream& s, t<v>& d) {\
    fore(x, d) s << x << " "; return s; }\
    c> istream& operator>>(istream& s, t<v>& d) {\
    fore(x, d) s >> x; return s; }
#define TU T, U
zz(v, T, tcT) zz(list, T, tcT)
zz(map, TU, tcTU) zz(unordered_map, TU, tcTU)
zz(set, T, tcT) zz(unordered_set, T, tcT)
#undef zz
#undef TU

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

tcT> int lwb(v<T>& a, const T& b) {return lb(all(a),b)-bg(a);}
tcT> int upb(v<T>& a, const T& b) {return ub(all(a),b)-bg(a);}

#include <bits/extc++.h>
using namespace __gnu_pbds;

tcT> using Ordered_set = tree<T, null_type,
 less<T>, rb_tree_tag, tree_order_statistics_node_update>;
tcT> using Ordered_multiset = tree<T, null_type,
 less_equal<T>, rb_tree_tag,
 tree_order_statistics_node_update>;

/* Set / Multiset usage: (indexing is [0,N))
 s.find_by_order(x) - iterator to x'th element 
 s.order_of_key(x) x's position
 s.find(x) - iterator to first occurrence of x
*/

tcT> using Trie = trie<T, null_type, 
trie_string_access_traits<>, pat_trie_tag,
trie_prefix_search_node_update>;

/* Trie usage:
 t.prefix_range(x) -> [begin, end) iterators of keys 
    in t that have x as a prefix
 t.split(x, t2) -> split all elements with key 
    larger than x into t2
*/

#include <ext/pb_ds/priority_queue.hpp> // Pairing heap
__gnu_pbds::priority_queue<int> pq;
