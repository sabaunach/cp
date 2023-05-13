/* https://vjudge.net/contest/531398#problem/I
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

using tii = tuple<int, int, int>;
using vi = vector<int>;

static char buf[450 << 20];
void* operator new(size_t s) {
    static size_t i = sizeof buf;
    assert(s < i);
    return (void*)&buf[i -= s];
}
void operator delete(void*) { }

struct Node {
    const static int inf = 1e9;
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = 0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val + r->val;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,m,s; cin>>n>>m>>s; s--;
    vector<pair<int, int>> edges;
    map<tii, int> vm;
    rep(i, 0, m) {
        int d,t; cin>>d>>t; t--;
        edges.emplace_back(d, t);
    }

    vector<int> v(n, INT_MAX);
    rep(i,0,n) chmin(v[(s+i)%n], i);
    rep(i,0,n) chmin(v[(s-i+n)%n], i);

    Node* tr = new Node(v, 0, sz(v));

    sort(all(edges));
    reverse(all(edges));

    // l_a, a, b, r_b
    for(auto&[d, t]: edges) {
        int a = tr->query(t, t + 1),
                b = tr->query((t+1)%n, (t+1)%n + 1);
        int l_a = tr->query((t+n-1)%n, (t+n-1)%n + 1),
                r_b = tr->query((t+2)%n, (t+2)%n + 1);
        if (r_b + 1 < a) a = r_b + 1;
        if (l_a + 1 < b) b = l_a + 1;
        tr->set(t, t + 1, b);
        tr->set((t+1)%n, (t+1)%n + 1, a);

        // propagate updates
        if (b + 1 < l_a) {
            // binary jumps to find delta (going left), should find last true
            int del = 0;
            for (int jmp = 1<<(31-__builtin_clz(n)); jmp > 0; jmp>>=1) {
                int q = tr->query((t-del-jmp-1+3*n)%n, (t-del-jmp-1+3*n)%n + 1);
                if (q - l_a == del+jmp) del += jmp;
            }

            if ((t-1-del+2*n)%n <= (t-1+n)%n)
                tr->add((t-1-del+2*n)%n, (t-1+n)%n + 1, -1);
            else {
                tr->add(0, (t-1+n)%n + 1, -1);
                tr->add((t-1-del+2*n)%n, n, -1);
            }
        }

        if (a + 1 < r_b) {
            int del = 0;
            for (int jmp = 1<<(31-__builtin_clz(n)); jmp > 0; jmp>>=1) {
                int q = tr->query((t+del+jmp+2)%n, (t+del+jmp+2)%n + 1);
                if (q - r_b == del+jmp) del += jmp;
            }
            if ((t+2)%n <= (t+del+2)%n)
                tr->add((t+2)%n, (t+del+2)%n + 1, -1);
            else {
                tr->add(0, (t+del+2)%n + 1, -1);
                tr->add((t+2)%n, n, -1);
            }
        }
    }

    rep(i,0,n) {
        cout << tr->query(i, i + 1) << "\n";
    }
}