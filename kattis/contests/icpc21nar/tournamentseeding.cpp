#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int int_fast32_t
#define ll int_fast64_t
#define ull uint_fast64_t
#define uint uint_fast32_t
#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)
#define ALL(a) (a).begin(), (a).end()
#define umap unordered_map
#define uset unordered_set
#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> rs(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> rs[i];
    }
    int tot = 0;
    sort(ALL(rs));
    for (int i = 1; i <= n; i++) {
        int num = (1 << i);
        int A = rs.size() - num;
        int B = rs.size() - num / 2;
        int a = A, b = B;
        while (a < B) {4
            if (rs[b] - rs[a] <= k) {
                tot++; a++; b++;
            } else {
                a++;
            }
        }
    }
    cout << tot;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}
