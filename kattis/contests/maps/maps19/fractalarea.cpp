#define _USE_MATH_DEFINES

#include <bits/stdc++.h>

using namespace std;

const double PI = M_PI;

int main() {
    vector<double> seq(51);
    vector<double> sums(51);
    seq[1] = 1; sums[1] = 1;
    seq[2] = 1; sums[2] = 2;
    for (int i = 3; i <= 50; i++) {
        seq[i] = seq[i - 1]*(3.0/4.0);
        sums[i] = sums[i - 1] + seq[i];
    }
    int r, n;
    cin >> n;
    cout << setprecision(12);
    while (cin >> r >> n) {
        cout << PI*r*r*sums[n] << endl;
    }
}
