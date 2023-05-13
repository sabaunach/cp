#include <bits/stdc++.h>

using namespace std;

// optimal -> invest followed by withdraw
// goal -> maximize $invest - $withdraw
// is this a unimodal function?
// no
// but maybe we can bsearch to find the day in which we invest an amount < the max we could invest
// then on that day bsearch the $invest which gives optimal sol
//

// 0..1
int b_search_1(int R, int Y, int D, int W) {
    auto pred = [&] (int m) -> bool {
        // profits of investing up to day m-1, m, and m+1
        return !feasible(v, m);
    };
    int l = -1, r = N/K+1;
    while (l + 1 < r) {
        int m = (l+r) / 2;
        if (pred(m)) r = m;
        else l = m;
    }
    return l;
}

/*
 *
 *
 *
 */

int main() {

}