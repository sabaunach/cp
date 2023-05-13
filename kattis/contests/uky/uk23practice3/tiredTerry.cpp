//
// Created by setha on 1/28/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, p, d;
    cin >> n >> p >> d;

    vector<int> asleep(n);
    int slept = 0, totalTired = 0;

    for (int i=0; i < n; ++i)
    {
        char c; cin >> c;
        asleep[i] = (c == 'Z') ? 1 : 0;
    }
    for (int i=0; i < p; ++i)
        slept += asleep[n-1-i];
    for (int i=0; i < n; ++i)
    {
        slept += asleep[i];
        slept -= asleep[(i-p+n)%n];
        if (slept < d) totalTired++;
    }
    cout << totalTired << endl;
}