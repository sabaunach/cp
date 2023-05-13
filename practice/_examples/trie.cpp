/**
 * This example shows how to use a PATRICIA trie for searching
 * for words with a given prefix.
 */

#include <cassert>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

using namespace std;
using namespace __gnu_pbds;

// A PATRICIA trie with a prefix-search node-updator type. Note that
// since the node updator is trie_prefix_search_node_update, then the
// container includes its method prefix_range.
// If this was null, the prefix_range method would not be available.
// Also supports trie_order_statistics_node_update
typedef null_type		mapped_type;
typedef trie_string_access_traits<> 	cmp_fn;
typedef pat_trie_tag 			tag_type;

// trie_order_statistics_node_update
typedef trie<string, mapped_type, cmp_fn, tag_type,
trie_prefix_search_node_update> trie_type;

// The following helper function takes a trie object and r_key, a
// const reference to a string, and prints all entries whose key
// includes r_key as a prefix.
void
print_prefix_match(const trie_type& t, const string& key)
{
    typedef trie_type::const_iterator 		const_iterator;
    typedef pair<const_iterator, const_iterator> 	pair_type;

    cout << "All keys whose prefix matches \"" << key << "\":" << endl;

    const pair_type match_range = t.prefix_range(key);
    for (const_iterator it = match_range.first; it != match_range.second; ++it)
        cout << *it << ' ';
    cout << endl;
}

int main()
{
    trie_type t;

    // Insert some entries.
    assert(t.insert("I").second == true);
    assert(t.insert("wish").second == true);
    assert(t.insert("that").second == true);
    assert(t.insert("I").second == false);
    assert(t.insert("could").second == true);
    assert(t.insert("ever").second == true);
    assert(t.insert("see").second == true);
    assert(t.insert("a").second == true);
    assert(t.insert("poem").second == true);
    assert(t.insert("lovely").second == true);
    assert(t.insert("as").second == true);
    assert(t.insert("a").second == false);
    assert(t.insert("trie").second == true);

    // Now search for prefixes.
    print_prefix_match(t, "");
    print_prefix_match(t, "a");
    print_prefix_match(t, "as");
    print_prefix_match(t, "ad");
    print_prefix_match(t, "t");
    print_prefix_match(t, "tr");
    print_prefix_match(t, "trie");
    print_prefix_match(t, "zzz");

    // Split the tree.
    trie_type t2;

    // Split all elements with key larger than 'love' into t2.
    // Tries must satisfy t1 < t2 or t1 > t2
    t.split("love", t2);

    print_prefix_match(t, "");
    print_prefix_match(t2, "");

    // Rejoin into t
    t.join(t2);

    print_prefix_match(t, "");

    // Find a key
    vector<string> queries = {"cou", "could"};
    for (auto q: queries) {
        auto it = t.find(q);
        cout << q << (it == t.end() ? " not" : "") << " found" << endl;
    }

    // iterator (goes through leaf nodes)
    for (const auto & i: t) {
        cout << i << " ";
    }
    cout << endl << endl;
    // tree dfs
    vector<trie_type::node_const_iterator> st;
    st.push_back(t.node_begin());
    while(!st.empty()) {
        auto it = st.back(); st.pop_back();
        cout << it.num_children() << " ";

        for (int i = 0; i < it.num_children(); i++) {
            st.push_back(it.get_child(i));
        }
    }

    return 0;
}

