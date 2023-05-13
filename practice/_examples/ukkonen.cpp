#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000000; // 2*(max string length)
typedef int schar; // type used for suffix tree
vector<schar> av; // array to construct tree from
schar alpha_max = 'z'; // alphabet max
unordered_map<schar, int> t[MAXN]; // transition array
unordered_set<int> ss[MAXN];  // substring indices
int l[MAXN], // left and right indices of av ...
r_[MAXN],       // ...  corresponding to incoming edge
r[MAXN],        // right boundary without term seq
p[MAXN],        // parent node
su[MAXN],       // suffix link
nn = 2,         // "new node" allocator
tv = 0,         // node of current suffix
                // (if mid-edge, lower node of edge)
tp = 0,         // position in string which corresponds
                // to position on edge > (l[tv], r[tv])
la = 0;         // the current character in the array
schar ts = alpha_max + 1;   // next terminating char

void ukkadd (schar c) {
    suff:;
    if (r_[tv]<tp) {
        if (t[tv].find(c) == t[tv].end()) {
            // insert new leaf node and do suffix link
            t[tv][c]=nn;  l[nn]=la; r[nn] = r_[nn]-1;
            size_t i; // scan for next terminating char
            for (i = la; av[i] <= alpha_max; i++);
            // make r[nn] stop before next term char
            r[nn] = i > la ? i - 1 : i;
            p[nn++]=tv;  tv=su[tv];  tp= r_[tv] + 1;
            goto suff;
        }
        tv=t[tv][c]; tp=l[tv]; // proceed to next edge
    }
    // if letter on edge equals c, go down edge
    if (tp==-1 || c==av[tp]) tp++;
    else {
        // split edge in two, creating two nodes:
        // create parent node marked by nn + 1
        l[nn]=l[tv];  r_[nn]=tp-1;  r[nn] = tp-1;
        p[nn]=p[tv];  t[nn][av[tp]]=tv;
        // add leaf node marked by nn + 1
        t[nn][c]=nn+1;  l[nn+1]=la;  p[nn+1]=nn;
        size_t i; // scan for next terminating char
        for (i = la; av[i] <= alpha_max; i++);
        // make r[nn] stop before next term char
        r[nn+1] = i > la ? i - 1 : i;
        // update info for current node
        l[tv]=tp;  p[tv]=nn;  t[p[nn]][av[l[nn]]]=nn;
        nn+=2;
        // if current node has become just a suffix,
        // adjust r accordingly
        r[tv] = r[tv] >= l[tv] ? r[tv] : l[tv];
        // suffix link stuff
        tv=su[p[nn - 2]]; tp=l[nn - 2];
        while (tp<=r_[nn-2]) {  tv=t[tv][av[tp]];
            tp+=r_[tv]-l[tv]+1; }
        if (tp==r_[nn-2]+1) su[nn - 2]=tv;
        else su[nn - 2]=nn;
        tp=r_[tv]-(tp-r_[nn-2])+2;  goto suff;
    }
}

void reset() {
    nn=2; tv=0; tp=0; la=0; su[0]=1; ts=alpha_max + 1;
    for (auto &m: t) m.clear();
    av.clear();
    for (int i = 0; i <= ts; i++) t[1][i] = 0;
    l[0]=-1; r_[0]=-1;
    l[1]=-1; r_[1]=-1;
}

void insert(const vector<schar> & s) {
    for (const auto & c: s)
        av.push_back(c);
    av.push_back(ts++);
    t[1][ts] = 0;
    fill(r_ + nn, r_ + min(av.size() * 2,
         (size_t)MAXN), av.size() - 1);
    fill(r + nn, r + min(av.size() * 2,
         (size_t)MAXN), av.size() - 2);
    for (; la < av.size(); la++) ukkadd(av[la]);
}

bool isSubstring(vector<schar> key) { // O(m) traversal
    // current node (if mid-edge, lower node)
    size_t node = 0;
    int    ia = 0, // index in key
    ib;            // index in current edge
    node:
    if (t[node].find(key[ia]) == t[node].end())
        return false;
    // go to next node
    node = t[node][key[ia]]; // node becomes lower node
    // dive down the existing edge
    ib = l[node] + 1; ia++;
    for (; ia < (int)key.size(); ia++, ib++) {
        // edge traversed successfully, go to node
        if (ib > r[node]) goto node;
        // fail to traverse on edge
        if (key[ia] != av[ib]) return false;
    }
    return true;
}

// NECESSARY for longestCommonSubstring()
// mark each node for which strings it is substring of
// this method is slow (O(n+?), n number of nodes)
// probably can do while adding nodes to the tree..
void markSubstrings() {
    for (auto &s: ss) s.clear();
    for (int node = 0; node < nn; node++) {
        if (!t[node].empty()) continue;
        schar termChar;
        if (av[l[node]] > alpha_max) // leaf is the
            termChar = av[r[node]]; // terminating char
        else termChar = av[r[node] + 1]; // get trmchar
        ss[node].insert(termChar);
        ss[0].insert(termChar);
        // go through parents, mark them
        int parent = p[node];
        do {
            if (ss[parent].find(termChar)
            != ss[parent].end())
                break; // parent is already marked
            ss[parent].insert(termChar);
            parent = p[parent];
        } while (parent != 0);
    }
}

typedef pair<int,int> ii;
// return node number of LCS of strings in tree
// SUBSTRINGS MUST BE MARKED FIRST
// if there are multiple, any is returned
// LCS is the deepest node common to all strings
vector<schar> longestCommonSubstring() {
    // {node, length of string leading to node}
    stack<pair<int, int>> stack;
    stack.push({0, 0});
    int maxLen = 0;
    int maxBegin = -1;
    while (!stack.empty()) {
        int curNode = stack.top().first;
        int curLen = stack.top().second;
        stack.pop();
        if (ss[curNode].size() != (ts - alpha_max - 1))
            continue; // current node not common to all
        if (curLen > maxLen) {
            maxLen = curLen;
            maxBegin = r[curNode] - curLen + 1;
        }
        for (ii child: t[curNode])
            stack.push({child.second, curLen
            + r[child.second] - l[child.second] + 1});
    }
    if (maxBegin == -1) return {};
    vector<schar> res(maxLen);
    copy(av.begin() + maxBegin, av.begin()
            + maxBegin + maxLen, res.begin());
    return res;
}

/*string longestPalindrome(string strS) {
    // constructs a suffix tree from S and R, R is the reverse of S
    // longest palindrome is longest common substr of S and R s.t. they start at the same place,
    // i.e. l[s in S] = a.length() - r[s in R] ( - 2 because of terminating sequences)
    string strR = strS;
    reverse(strR.begin(), strR.end());
    reset(); insert(strS); insert(strR);
    // modified markSubstrings() algorithm, will mark substrings with each place they occur (right index)
    vector<unordered_set<int>> si(nn);
    for (int node = 0; node < nn; node++) { // go through each node
        if (!t[node].empty())
            continue;
        // if node is a leaf node
        int rIndex;
        // get right index of end of suffix represented by leaf
        if (av[r[node]] > alpha_max)
            rIndex = r[node] - 1; // leaf is the terminating character
        else
            rIndex = r[node];
        si[node].insert(rIndex);
        // go through parents, mark their right index
        int curr = node;
        // edge case: if we just came from a leaf that consisted of only terminating char,
        // we won't want to actually "travel up" anything on first iteration
        if (av[r[node]] > alpha_max)
            rIndex += 1;
        while (curr != 0) {
            rIndex -= r[curr] - l[curr] + 1; // travel up the edge
            curr = p[curr];
            si[curr].insert(rIndex);
        }
    }
    // modified longestCommonSubstring also ensures that for s in S and R,
    // they are in the same spot
    // DFS
    markSubstrings();
    stack<pair<int, int>> stack; // {node, length of string leading to node}
    stack.push({0, 0});
    int maxLen = 0, maxNode = 0;
    string maxStr = ""; // return value
    while (!stack.empty()) {
        int curNode = stack.top().first;
        int curLen = stack.top().second;
        stack.pop();
        if (ss[curNode].size() != 2)
            continue; // the current node is not common to both strings
            // check to see if for any occurences of s in S, there are matching
            // occurrences of s in R
            bool match = false;
            for (int i: si[curNode]) {
                int left = i - curLen + 1; // l[s in S]
                if (si[curNode].find(a.length() - left - 2) != si[curNode].end()) {
                    match = true;
                    break;
                }
            }
            if (match) {
                if (curLen > maxLen) {
                    maxLen = curLen;
                    maxNode = curNode;
                    maxStr = a.substr(r[curNode] - curLen + 1, curLen);
                }
            }
            for (ii child: t[curNode])
                stack.push({child.second, curLen + r[child.second] - l[child.second] + 1});
    }
    return maxStr;
}*/

/*vector<int> allSubstringOccurrences(string key, int node = -1, int substrLength = -1) {
    // traverse suffix tree from root. if traversal does not fail, key is substring of a.
    // to find all starting indexes, look at each suffix that is prefixed by our substring,
    // i.e. all leaf nodes branching from our prefix. start index is given by string length - length of suffix + 1.
    // implemented with DFS
    vector<int> result;
    if (node == -1) {
        ii substr = isSubstring(key);
        if (substr.first == -1)
            return result;
        node = substr.first;
        substrLength = substr.second;
    }
    substrLength += r[node] - l[node] + 1;
    if (t[node].empty()) { // base case: node is leaf
        return result = {(int)a.size() - substrLength + 1};
    }
    for (auto m: t[node]) { // compute children
        vector<int> tempResult = allSubstringOccurrences(key, m.second, substrLength);
        result.insert(result.end(), tempResult.begin(), tempResult.end());
    }
    return result;
}

int repeatedSubstrings() {
    // get the number of unique repeated substrings
    // if a node is internal, the substring represented by that node is repeated.
    // so count # of internal nodes. (account for compression in suffix tree, too.)
    for (int i = 2; i < nn; i++) {

    }
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<schar>> input;
    reset();
    for(int i = 0; i < n; i++) {
        string in; cin >> in;
        vector<schar> v(in.length());
        copy(in.begin(), in.end(), v.begin());
        insert(v);
        input.push_back(v);
    }

    markSubstrings();
    cout << longestCommonSubstring().size();
}