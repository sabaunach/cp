#include <bits/stdc++.h>

using namespace std;

void solve() {
    double r; int n;
    cin >> r >> n;
    // pi*r^2 + 4*pi*((r/2)^2) + 12*...
    // pi*r^2*(1+(12/16)+(
    // 1,4/2^2,12/4^2,36/8^2,
    // 2^2, 2^4, 2^9, 2^16, ...
    // sum((3^i)/(2^i)
    double sum = 1;
    if (n > 1) sum = 2;

    //
    for (int i = 3; i <= n; i++) {
        sum += pow(3.0, i-2)/pow(2.0, (i-2)*(i-2));
    }
    cout << setprecision(12) << M_PI*pow(r, 2)*sum << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}