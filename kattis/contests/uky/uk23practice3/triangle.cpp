//
// Created by setha on 1/28/2023.
//
#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;

int det (pair<ii,ii> l1, pair<ii,ii> l2)
{
    return (l1.first.first - l1.second.first)*(l2.second.second - l2.first.second) - (l2.second.first - l2.first.first)*(l1.first.second - l1.second.second);
}

int xInt (pair<ii, ii> l1, pair<ii,ii> l2)
{
    int D = det(l1, l2);
    double t = (1.0*((l2.second.second - l2.first.second) * (l1.first.first - l2.first.first) + (l2.first.first - l2.second.first) * (l1.first.second - l2.first.second))) / D;
    return l1.first.first + (l1.second.first - l1.first.first)*t;
}

int yInt (pair<ii, ii> l1, pair<ii,ii> l2)
{
    int D = det(l1, l2);
    double t = (1.0*((l1.second.second - l1.first.second) * (l1.first.first - l2.first.first) + (l1.first.first - l1.second.first) * (l1.first.second - l2.first.second))) / D;
    return l1.first.second + (l1.second.second - l1.first.second)*t;
}

int main ()
{
    int n;
    cin >> n;

    vector<pair<ii,ii>> lines(n);

    for (int i=0; i < n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = make_pair(make_pair(x1,y1), make_pair(x2,y2));
    }

    double maxP = -1;
    for (int i=0; i < n; ++i)
        for (int j=i+1; j < n; ++j)
        {
            if (det(lines[i], lines[j]) == 0) continue;
            for (int k=j+1; k< n; ++k)
            {
                if (det(lines[i], lines[k]) == 0 || det(lines[j], lines[k]) == 0) continue;
//                cout << xInt(lines[i], lines[j]) << " " << yInt(lines[i], lines[j]) << endl;
//                cout << xInt(lines[k], lines[j]) << " " << yInt(lines[k], lines[j]) << endl;
//                cout << xInt(lines[i], lines[k]) << " " << yInt(lines[i], lines[k]) << endl;
                double P = hypotl(xInt(lines[i], lines[j]), yInt(lines[i], lines[j]))
                        + hypotl(xInt(lines[k], lines[j]), yInt(lines[k], lines[j]))
                        + hypotl(xInt(lines[i], lines[k]), yInt(lines[i], lines[k]));
                if (P > maxP) maxP = P;
            }
        }
    if (maxP == -1) cout << "no triangle";
    else cout << maxP;
    cout << endl;
}