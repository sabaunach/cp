#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, q;
    cin >> n >> q;

    vector<int> loc(n);
    for (int i=0; i < n; ++i)
        cin >> loc[i];
    for (int i=0; i < q; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        if (A == 1) loc[B-1] = C;
        else cout << abs(loc[B-1] - loc[C-1]) << endl;
    }
}