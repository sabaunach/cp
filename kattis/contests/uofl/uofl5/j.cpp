#include <bits/stdc++.h>
using namespace std;

int main() {
    int l,p;
    cin >> l >> p;

    vector<double> scores(l+p, 0);
    for(int i = 0; i < l; i++)
        cin >> scores[i];

    unordered_set<int> drop;
    double lp,rp,t;
    int x,y;
    for(int i = 0; i < p; i++) {
        cin >> lp >> rp >> x >> y;
        x--; y--;

        drop.erase(x);
        drop.erase(y);
        drop.insert(l+i);

        t = lp + rp;
        scores[l+i] = (scores[x]*lp + scores[y]*rp) / t;
    }

    double ans = 0;
    for(auto i : drop)
        ans = max(ans, scores[i]);
    cout << setprecision(100) << ans << endl;
}