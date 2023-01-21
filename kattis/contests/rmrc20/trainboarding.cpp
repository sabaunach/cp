#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main ()
{
    int n, L, p;
    cin >> n >> L >> p;

    vector<int> boarded;
    boarded.assign(n, 0);

    int maxDist = -1, maxBoarded = -1;
    for (int i=0; i < p; ++i)
    {
        int x, d;
        cin >> x;
        int c = (x/L >= n) ? n-1 : x/L;
        boarded[c]++;
        d = abs((x-c*L) - L/2);
        if (d > maxDist) maxDist = d;
    }

    for (int i=0; i < n; ++i)
        if (boarded[i] > maxBoarded)
            maxBoarded = boarded[i];

    cout << maxDist << endl << maxBoarded << endl;
}
