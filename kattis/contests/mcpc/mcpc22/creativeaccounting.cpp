#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, l, h;
    cin >> n >> l >> h;

    vector<int> p(n);
    for (int i=0; i < n; ++i)
        cin >> p[i];

    long long minP = INT64_MAX, maxP = -1;
    for (int sz=l; sz <= h; ++sz)
    {
        vector<int> cnt(sz, 0);
        
        int sum = 0;
        for (int i=0; i < n+sz-1; ++i)
        {
            if (i - sz >= 0) sum -= p[i-sz];
            if (i < n) sum += p[i];
            if (sum > 0) cnt[i % sz]++;
        }
        sort(cnt.begin(), cnt.end());
        if (cnt[0] < minP) minP = cnt[0];
        if (cnt[sz-1] > maxP) maxP = cnt[sz-1];
    }
    cout << minP << " " << maxP << endl;
}