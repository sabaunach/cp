//
// Created by setha on 2/1/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    double h, r, da, dw;
    cin >> h >> r >> da >> dw;

    if (dw == da) cout << h/2 << endl;
    else cout << setprecision(15) << (h / (dw - da)) * (-da + sqrt(da*da + (dw - da)*da)) << endl;
}