#include <bits/stdc++.h>

using namespace std;

const int N=1000000; // max possible number of nodes

// ukkonen suffix tree from cp-algo website

vector<int> av; // string to construct tree from
string a;       // string representation of av (terminating characters are represented by $)
unordered_map<int, int> t[N];     // array of transitions (state, letter)
unordered_set<int> ss[N];         // substrings representd by node (initialize with markSubstrings())
int l[N],       // left...
    r_[N],      // ... and right boundaries of substring corresponding to incoming edge
    r[N],       // right boundary of substring corresponding to incoming edge (without terminating sequence)
    p[N],       // parent of the node
    s[N],       // suffix link
    nn,         // number of nodes (plus one extra)
    ns,         // number of strings
    tv,         // node of current suffix (if we're mid-edge, lower node of the edge)
    tp,         // position in string which corresponds to position on the edge (between l[tv] and r[tv])
    la,         // the current character in the string
    ts;         // next terminating character to be used

void ukkadd (int c) {
    suff:;
    if (r_[tv]<tp) {
        if (t[tv].find(c) == t[tv].end()) { // insert new leaf node (and do suffix link)
            t[tv][c]=nn;  l[nn]=la; r[nn] = r_[nn]-1;
            // scan for next terminating character, make r[nn] stop before that
            int i; for (i = la; av[i] < 128; i++); // Don't miss the semi colon!
            r[nn] = i > la ? i - 1 : i;
            p[nn++]=tv;  tv=s[tv];  tp=r_[tv]+1;  goto suff;
        }
        tv=t[tv][c]; tp=l[tv]; // proceed to next edge
    }
    if (tp==-1 || c==av[tp]) tp++; // if letter on edge equals c, go down edge
    else {
        // split edge in two, creating two nodes:
        // create parent node marked by nn + 1, parent of current node and leaf
        l[nn]=l[tv];  r_[nn]=tp-1;  r[nn] = tp-1;  p[nn]=p[tv];  t[nn][av[tp]]=tv;
        // add leaf node marked by nn + 1
        t[nn][c]=nn+1;  l[nn+1]=la;  p[nn+1]=nn;
        // scan for next terminating character, make r[nn+1] stop before that
        int i; for (i = la; av[i] < 128; i++); // Don't miss the semi colon!
        r[nn+1] = i > la ? i - 1 : i;
        // update info for current node
        l[tv]=tp;  p[tv]=nn;  t[p[nn]][av[l[nn]]]=nn;  nn+=2;
        // if current node has become just a suffix, adjust r accordingly
        r[tv] = r[tv] >= l[tv] ? r[tv] : l[tv];
        // suffix link stuff
        tv=s[p[nn-2]];  tp=l[nn-2];
        while (tp<=r_[nn-2]) {  tv=t[tv][av[tp]];  tp+=r_[tv]-l[tv]+1;}
        if (tp==r_[nn-2]+1)  s[nn-2]=tv;  else s[nn-2]=nn;
        tp=r_[tv]-(tp-r_[nn-2])+2;  goto suff;
    }
}

// build for multiple strings (generalized suffix tree) (OFFLINE)
void build(vector<string> strings) {
    nn=2; tv=0; tp=0; la=0; s[0]=1; ts=128; ns = strings.size();
    for (auto &m: t) m.clear();
    for (int i = 0; i <= N; i++) t[1][i] = 0;

    int size = 0;
    for (auto str: strings) // compute size of string we are inserting
        size += str.size() + 1;
    a = string(size, '\0');
    av = vector<int>(size);
    for (auto str: strings) { // build string we are inserting, and reference string
        for (int i = 0; i<(int)str.size(); i++, la++) {
            a[la] = str[i];
            av[la] = str[i];
        }
        a[la] = '$'; av[la] = ts++;
        la++;
    }
    // finish initialization and insert the characters
    fill(r_,r_+N,(int)size-1);
    fill(r,r+N,(int)size-2);
    l[0]=-1; r_[0]=-1;
    l[1]=-1; r_[1]=-1;
    for (la = 0; la<size; la++)
        ukkadd(av[la]);
}

bool isSubstring(string key) { // O(m), m is size of key
    // traverse suffix tree from root. if traversal does not fail, key is substring of a
    size_t node = 0;   // current node (if mid-edge, lower node)
    int    ia = 0,     // index in key
           ib;         // index in current edge
    node:
    if (t[node].find(key[ia]) == t[node].end())
        return false;
    // go to next node
    node = t[node][key[ia]]; // node becomes lower node
    // dive down the existing edge
    ib = l[node] + 1; ia++;
    for (; ia < (int)key.size(); ia++, ib++) {
        if (ib > r[node]) goto node; // edge traversed successfully, go to node
        if (key[ia] != a[ib]) return false; // fail to traverse on edge
    }
    return true;
}

// NECESSARY for longestCommonSubstring()
void markSubstrings() { // mark each node for which strings it is a substring of
    // this method is slow (O(n), n is number of nodes), it can be done while
    // adding nodes to the tree but I haven't figured out a way to get that to work
    for (auto &s: ss) s.clear();
    for (int node = 0; node < nn; node++) { // go through each node
        if (!t[node].empty())
            continue;
        // if node is a leaf node
        int termChar;
        if (av[l[node]] >= 128)
            termChar = av[r[node]]; // leaf is the terminating character
        else
            termChar = av[r[node] + 1]; // get terminating character from substring
        ss[node].insert(termChar);
        ss[0].insert(termChar);
        // go through parents, mark them
        int parent = p[node];
        do {
            if (ss[parent].find(termChar) != ss[parent].end())
                break; // parent is already marked
            ss[parent].insert(termChar);
            parent = p[parent];
        } while (parent != 0);
    }
}

typedef pair<int,int> ii;

string longestCommonSubstring() { // return node number of longest common substring of stings in tree
    // SUBSTRINGS MUST BE MARKED BEFORE THIS FUNCTION CAN WORK
    // if there are multiple, the one that is returned is not specified
    // longest common substring is just the deepest node common to all strings
    // DFS
    stack<pair<int, int>> stack; // {node, length of string leading to node}
    stack.push({0, 0});
    int maxLen = 0, maxNode = 0;
    string maxStr = ""; // optional (return value)
    while (!stack.empty()) {
        int curNode = stack.top().first;
        int curLen = stack.top().second;
        stack.pop();
        if (ss[curNode].size() != (size_t)ns)
            continue; // the current node is not common to all strings
        if (curLen > maxLen) {
            maxLen = curLen;
            maxNode = curNode;
            maxStr = a.substr(r[curNode] - curLen + 1, curLen);
        }
        for (ii child: t[curNode])
            stack.push({child.second, curLen + r[child.second] - l[child.second] + 1});
    }
    return maxStr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n; cin >> n;
    vector<string> input;
    for(int i = 0; i < n; i++) {
        string in; cin >> in;
        input.push_back(in);
    }
    build(input);

    markSubstrings();
    cout << longestCommonSubstring().length() << endl;
}
