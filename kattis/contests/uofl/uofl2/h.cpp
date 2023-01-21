#include <bits/stdc++.h>

using namespace std;

double PI = 3.14159265358979323846264;
double acc = .00000000000001;
int nbounce;
double w, l;

pair<int, float> sim(double b) {
    // first bounce
    double h = (w/2.0)*tan(b);
    b = atan(2*tan(b));
    if (h > l) {
        return {0, -1};
    }
    int cnt = 1;
    double h_next = h + (w)*tan(b);
    while (h_next < l) {
        cnt++;
        b = atan(2*tan(b));
        h_next = h + (w)*tan(b);
    }
    // last step
    double x = tan(PI / 2 - b)*(l - h);
    return {cnt, x};
}

double bsearch(double l, double r) {
    double m;
    while (r - l > acc) {
        m = l + (r - l) / 2.0;
        auto res = sim(m);
        if (res.first < nbounce) {
            r = m;
        } else if (res.first > nbounce) {
            l = m;
        } else {
            // print range for now
            if (res.second < w/2.0) {
                l = m;
            } else if (res.second > w/2.0) {
                r = m;
            }
        }
    }
    return m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> nbounce >> w >> l;
    cout << setprecision(12) << bsearch(0.0, PI/2.0) * (180 / PI);
}