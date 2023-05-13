#include <bits/stdc++.h>

using namespace std;


// each player picking line which maximizes their score
// 1st knows that 2nd will try to maximize their score
// <-> kind of minimize first score?
/*
 * if given 1st line
 * we can determine 2nd line in like log(n) time
 * we should be fine
 *
 * sweepline:
 * group points by (y)
 * maintain points sorted by x, those on L and on R
 * at each point, to determine the best horizontal line:
 *  want to maximize UL and DR quadrants' # points
 *  specifically: stan wants to maximize his smallest possible score
 *
 *
 *  so keep at each x-point in datastructure
 *  # points we get in UL and DR for this horizontal line
 *  so needs RURQ
 *
 *
 *
 */


typedef vector<int> vi;
const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){}
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
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
            val = max(l->val, r->val);
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
    int N; cin >> N;


    // need to alloc x points
    vector<pair<int, int>> pts;
    for (int i = 0; i < N; i++) {
        int x,y; cin >> x >> y;
        pts.emplace_back(x, y);
    }
    sort(pts.begin(), pts.end());
    int alloc = 0;
    vector<vi> pts_x = {{pts[0].second}};
    map<int, vi> pts_y = {{pts[0].second, {pts[0].first}}};
    for (int i = 1; i < pts.size(); i++) {
        if (pts[i].first != pts[i-1].first)
            alloc++, pts_x.push_back({});
        pts_x.back().push_back(pts[i].second);
        pts_y[pts[i].second].push_back(alloc);
    }

    // start with -inf line, so DR has basically suffix sums (minus points on that x-coord)
    vector<int> v(pts_x.size());
    v[0] = accumulate(v.begin(), v.end(), 0) - pts_x[0].size();
    for (int i = 1; i < v.size(); i++) {
        v[i] = v[i-1] - pts_x[i].size();
    }
    Node* tr = new Node(v, 0, v.size());

    map<int, unordered_set<int>> ans_states;
    for (auto y_it = pts_y.begin(); y_it != pts_y.end(); y_it++) {
        // draw line
        for (auto x: y_it->second) {
            tr->add(0, x, -1);

        }
        // do query



        // move points
    }
}