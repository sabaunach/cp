//
// Created by setha on 1/21/2023.
//
#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    int YmaxStr = 0, YcurrStr = 0, Ypts = 0, YmaxL = 0;
    int NmaxStr = 0, NcurrStr = 0, Npts = 0, NmaxL = 0;
    string s;

    for (int i=0; i < n; ++i)
    {
        cin >> s;
        if (s == "Yraglac")
        {
            YcurrStr++; Ypts++;
            if (NcurrStr) NcurrStr = 0;
            if (Ypts - Npts > YmaxL) YmaxL = Ypts - Npts;
            if (YcurrStr > YmaxStr) YmaxStr = YcurrStr;
        } else {
            NcurrStr++; Npts++;
            if (YcurrStr) YcurrStr = 0;
            if (Npts - Ypts > NmaxL) NmaxL = Npts - Ypts;
            if (NcurrStr > NmaxStr) NmaxStr = NcurrStr;
        }
    }

    int win1, win2;
    if (NmaxL > YmaxL) win1 = 'N';
    else if (NmaxL == YmaxL) win1 = 'T';
    else win1 = 'Y';

    if (NmaxStr > YmaxStr) win2 = 'N';
    else if (NmaxStr == YmaxStr) win2 = 'T';
    else win2 = 'Y';

    cout << ((win1 == win2) ? "Agree" : "Disagree") << endl;
}