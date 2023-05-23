#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define fore(a,x) for (auto& a: x)

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int mn1, mx1, mn2, mx2; cin >> mn1 >> mx1 >> mn2 >> mx2;
        int cp1 = sqrt(mx1), cp2 = sqrt(mx2);
        while (cp1*cp1 < mx1) cp1++; while (cp1*cp1 > mx1) cp1--;
        while (cp2*cp2 < mx2) cp2++; while (cp2*cp2 > mx2) cp2--;
        int cp = max(cp1, cp2);
        set<int> d1, d2;
        int ans = 1;
        rep(d,2,cp) {
            if (mx1/d - mn1/d >= 1) {
                if (mx2/d - mx1/d >= 1) {
                    
                }
                int k = mn1/d + 1;
                while (k*d <= cp1) {
                    if (mx2/d - mx1/d >= 1) {

                    }
                }
                    d1.insert(k++);
            }
            if (mx2/d - mn2/d >= 1) {
                d2.insert(d);
                int k = mn2/d + 1;
                while (k*d <= cp2)
                    d2.insert(k++);
            }
        }
        cout << t << ": \n";
        fore(x, d1) cout << x << " "; cout << "\n";
        fore(x, d2) cout << x << " "; cout << "\n";



        cout << "\n";
    }
}