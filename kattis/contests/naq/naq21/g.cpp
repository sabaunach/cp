#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, first = 0, last, cf, cl;
    cin >> n >> t;
    bitset<100000> errs;
    while (t--) {
        int e;
        cin >> e;
        if (first == 0)
            first = e;
        errs.set(e);
        last = e;
    }
    int cnt = 1;
    while (errs[cnt])
        cnt++;
    cf = cnt;
    cnt = n;
    while (errs[cnt])
        cnt--;
    cl = cnt;
    cout << "Errors: ";
    for (int i = 1; i <= n; i++) {
        int f, l;
        if (errs[i]) {
            f = i;
            if (!errs[i + 1]) {
                if (f == first)
                    cout << f;
                else if (f == last)
                    cout << " and " << f;
                else
                    cout << ", " << f;
            } else {
                i++;
                while (errs[i] && i <= n) {
                    l = i;
                    i++;
                }
                if (f == first)
                    cout << f << "-" << l;
                else if (l == last)
                    cout << " and " << f << "-" << l;
                else
                    cout << ", " << f << "-" << l;
            }
        }
    }
    cout << endl;
    cout << "Correct: ";
    for (int i = 1; i <= n; i++) {
        int f, l;
        if (!errs[i]) {
            f = i;
            if (errs[i + 1] || i + 1 > n) {
                if (f == cf)
                    cout << f;
                else if (f == cl)
                    cout << " and " << f;
                else
                    cout << ", " << f;
            } else {
                i++;
                while (!errs[i] && i <= n) {
                    l = i;
                    i++;
                }
                if (f == cf)
                    cout << f << "-" << l;
                else if (l == cl)
                    cout << " and " << f << "-" << l;
                else
                    cout << ", " << f << "-" << l;
            }
        }
    }
}
