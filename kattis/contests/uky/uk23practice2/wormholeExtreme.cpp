//
// Created by setha on 1/21/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main ()
{
#define int long long
#define double long double
    int n;
    cin >> n;

    vector<int> a(n), d(n);

    for (int i=0; i < n; ++i)
        cin >> d[i] >> a[i];

    double E=0, Emin = 0, t=0;

    for (int i=0; i < n; ++i)
    {
        E += a[i] * d[i];
        if (E < Emin) Emin = E;
    }
    E = abs(Emin);
    double v = sqrt(2*E);

    double v0 = v, vf;
    for (int i=0; i < n; ++i)
    {
        vf = sqrtl(v0*v0 + 2*a[i]*d[i]);
        t += (vf - v0) / a[i];
        v0 = vf;
    }
    cout << setprecision(12) << v << " " << t << endl;
}