// Team: uky bbn csm fans
// Room: opera C


#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vi v(n); for (auto&x: v) cin >> x;

    vector<vi> pre(3, vi(n)), post(3, vi(n));
    vector<vector<vi>> con(3, vector<vi>(3, vi(n+1)));

    for (int k = 0; k < 3; k++) {
        pre[k][0] = v[0] == k;
        post[k][n-1] = v[n-1] == k;
        for (int i = 1; i < n; i++) {
            pre[k][i] = pre[k][i-1] + (v[i] == k);
            post[k][n-i-1] = post[k][n-i] + (v[n-i-1] == k);
        }
    }
//    rep(a,0,3) {
//        rep(i,0,n) {
//            cout << post[a][i] << " ";
//        }
//        cout << endl;
//    }
//
//    rep(a,0,3) {
//        rep(i,0,n) {
//            cout << pre[a][i] << " ";
//        }
//        cout << endl;
//    }

    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (a == b) continue;
            vi diff(n);
            priority_queue<int> pq;
            int offset = 0;
            rep(i,0,n) diff[i] = post[b][i] - post[a][i];
            for (int i = n-1; i >= 0; i--) {
                offset += (v[i] == a);
                con[a][b][i] = max({
                    i < n-1 ? con[a][b][i+1] + v[i]==a : 0,
                    pq.size() ? offset + pq.top() : 0,
                    post[a][i],
                    post[b][i]
                    }
                );
                pq.push(diff[i]);
            }
        }
    }

//    rep(a,0,3) { rep (b,0,3) {
//        if (a == b) continue;
//        cout << a << " " << b << endl;
//        rep(i,0,n) {
//            cout << con[a][b][i] << " ";
//        }
//        cout << endl;
//        }
//    }

    int ans = 0;
    rep(a,0,3) {
        rep(b,0,3) rep(c,0,3) {
            if (a == b || b == c || a == c) continue;
            ans = max({ans, post[a][n-1], con[b][c][0]});
            rep(i,1,n) {
                ans = max(ans, pre[a][i-1] + con[b][c][i]);
            }
        }
    }
    cout << ans << endl;
}

/*
4 4 4 4 3 2 1 0 0 0 
3 2 1 0 0 0 0 0 0 0 
3 3 3 3 3 3 3 3 2 1 
0 0 0 1 2 3 4 4 4 4 
1 2 3 3 3 3 3 3 3 3 
0 0 0 0 0 0 0 1 2 3 
0 1
0 0 0 1 2 3 4 4 4 4 
0 2
0 0 0 1 2 3 4 4 4 4 
1 0
1 2 3 3 3 3 3 3 3 3 
1 2
1 2 3 3 3 3 3 3 3 3 
2 0
0 0 0 0 0 0 0 1 2 3 
2 1
0 0 0 0 0 0 0 1 2 3 
5
*/