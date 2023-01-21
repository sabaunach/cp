#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

struct pt {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) return 0;

        vector<pt> pts;
        for (int i = 0; i < n; i++) {
            pt p;
            cin >> p.x >> p.y;
            pts.push_back(p);
        }

        int i = 0;
        if (pts[i].x >= pts[i + 1].x) {
            if (pts[i].y > pts[i + 1].y) {
                printf("CW ");
                reverse(pts.begin(), pts.end());
            } else {
                printf("CCW ");
            }
        } else {
            if (pts[i].y < pts[i + 1].y) {
                printf("CW ");
                reverse(pts.begin(), pts.end());
            } else {
                printf("CCW ");
            }
        }

        int area = 0;
        for (int i = 0; i < pts.size(); i++) {
            int x1 = pts[i].x, x2 = pts[(i + 1) % n].x;
            int y1 = pts[i].y, y2 = pts[(i + 1) % n].y;
            area += x1*y2 - y1*x2;
        }
        printf("%.1f\n", abs(area / 2.0));
    }
}