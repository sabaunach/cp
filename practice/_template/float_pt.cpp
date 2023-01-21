#include <bits/stdc++.h>

using namespace std;

#define x() real()
#define y() imag()
typedef complex<double> pt;
bool operator <(const pt& a, const pt& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
