#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

vector<vector<int>> v;
int n;
struct iter {
    int xdir, ydir, i, j;
    iter(int xdir, int ydir, int o)
    : xdir(xdir), ydir(ydir) {
        if (xdir && !ydir) {
            i = o;
            j = 0;
        } else if (!xdir && ydir) {
            i = 0;
            j = o;
        }
        else if (xdir<0 && ydir>0) {
            if (o<n) {
                i = 0;
                j = o;
            } else {
                i = o-n+1;
                j = n-1;
            }
        } else if (xdir>0 && ydir>0) {
            if (o<n) {
                i = 0;
                j = n-o-1;
            } else {
                i = o-n+1;
                j = 0;
            }
        }
    }
    iter operator++(int) {iter ret = *this; i += ydir; j += xdir; return ret;}
    iter operator-(int x) { iter ret = *this; ret.i -= x*ydir; ret.j -= x*xdir; return ret; }
    int operator*() { return v[i][j]; }
    bool done() { return i<0 || i>=n || j<0 || j>=n; }
};

int main() {
    int q; cin >> n >> q;
    v = vector<vector<int>>(n, vector<int>(n));
    for (auto &r: v) for (auto &x: r) cin >> x;
    ll ans = 0, prod, z;
    struct arg { int xdir, ydir, mx; };
    for (auto[xdir,ydir,mx]: vector<arg>{{1,0,n}, {0,1,n}, {-1,1,2*n-1}, {1,1,2*n-1}}) {
        for (int i = 0; i < mx; i++) {
            prod = 1;
            z = 0;
            for (auto it = iter(xdir, ydir, i); !it.done(); it++) {
                if (*it == 0) {
                    z = 0;
                    prod = 1;
                } else {
                    prod *= *it;
                    if (z++ >= q) prod /= *(it - q);
                    UMAX(ans, prod);
                }
            }
        }
    }
    cout << ans << endl;
}