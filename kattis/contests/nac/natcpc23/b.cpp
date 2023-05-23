/* https://vjudge.net/contest/556429#problem/B
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

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    /*
    if shelf isn't full we can insert anywhere on shelf
    -> if shelf isn't full the position of 0s does not really matter
    
    need to arrange shelves into wanted order
    impossible <-> shelves are all full and not the same
    otherwise possible
    minimize # lifts <-> when we move a book to its shelf, want to put it in order
    if limited # 0's available, its awkward?
    its kind of like swapping the 0 around to put other stuff in place
    swapping two books costs
    if not on same shelf: 3 if shelves are full, 2 if one shelf not full
    if on same shelf: 2 if shelf is full, 1 if shelf not full


    sum # books + that need to move, and # shelves that need moves?

    1, 4, 6 -> 3 books that need to move
    need an extra move to use the 0

    if rearranging a shelf, # books that need to move
    5 4 3 2 1
    1 2 3 4 5
    -> min(n) picking some elt as pivot (stationary)?

    5 3 2 1 4
    1 2 3 4 5
    



    1 5 2 3 0 4
    1 2 3 4 5 0

    1 3 4 2 5
    1 3 4 0 5
    1 2 3 4 5
    each 

    1 2 0
    3 5 4
    1 2 0
    4 5 3
    -> 1 2 3, 0 5 4, 3 4 5 ; 3 lifts


    1 2
    3 0
    3 1
    2 0



    */
}