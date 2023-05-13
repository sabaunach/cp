#include <bits/stdc++.h>
using namespace std;

int main ()
{
#define int long long
    int a, b, c;
    cin >> a >> b >> c;

    if (a != 4 || b % 2 || b*b < 16*c)
    {
        cout << "impossible" << endl;
        return 0;
    }

    int d = sqrt(b*b - 16*c);
    int k = b + d;
    if (d*d != b*b - 16*c || k % 4)
    {
        cout << "impossible" << endl;
        return 0;
    }
    k /= 4;
    cout << k+2 << " " << (b/2-k)+2 << endl;
}