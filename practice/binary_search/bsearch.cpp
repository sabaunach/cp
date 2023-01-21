#include <bits/stdc++.h>

using namespace std;

// simple imlpementation
int b_search_simple(int x, vector<int>& v) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        int m = (l+r) / 2;
        if (x <= v[m]) r = m;
        else l = m + 1;
    }
    return l;
}

// more generic implementation
int b_search_pred(int x) {
    // consider 00001111
    // initialize l and r such that the predicate at l is false and the predicate at r is true
    // our predicate should evaluate true if x lies in [m, r)
    // and false if x lies in (l,m)
    auto pred = [&] (int m) -> bool {return m*m>x; };
    int l = -1, r = x+1;
    while (l + 1 < r) {
        int m = (l+r) / 2;
        if (pred(m)) r = m;
        else l = m;
    }
    // Now, l + 1 = r, pred(l) == false, and pred(r) = true
    // Based on the problem, choose either l or r
    return l;
}

int main() {
    for (int i = 0; i <= 36; i++) {
        cout << i << " " << b_search_pred(i) << endl;
    }
    cout << b_search_pred(10) << endl;
}