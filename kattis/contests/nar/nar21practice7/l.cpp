#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define double long double

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<double> t = vector<double>(m), p = vector<double>(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i];
        double p_in; cin >> p_in;
        p[i] = 1 - p_in;
    }
    double prevEV = 0;
    for (int i = 0; i < n; i++) {
        double minEV = ((t[0] + prevEV) + k*(1-p[0])) / p[0];
        for (int j = 1; j < m; j++) {
            minEV = min(minEV, ((t[j] + prevEV) + k*(1-p[j])) / p[j] );
        }
        prevEV = minEV;
    }
    cout << prevEV;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}
