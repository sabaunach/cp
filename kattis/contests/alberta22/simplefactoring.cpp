#include <bits/stdc++.h>

using namespace std;

bool solve() {
    long long a,b,c; cin >> a >> b >> c;

    if (b*b-4*a*c<0) return false;
    long double x = sqrt(b*b-4*a*c);

    if (floor(x)!=ceil(x)) return false;
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}