#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const double PI = M_PI;

int main() {
    cout << setprecision(12);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int n, l, d, g;
        cin >> n >> l >> d >> g;
        // formula for regular n-sided polygon area + grabbed area
        cout << n*l*l/(4.0*tan((PI)/n)) + n*l*(d*g) + PI*(d*g)*(d*g) << endl;
    }
}
