#include <bits/stdc++.h>

using namespace std;

int main() {
    #define int long long
    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(4, 0));
    set<int> ycoords;
    for (int i = 0; i < n; i++) {
        vector<int> pts(4);
        for (auto& pt: pts) {
            string num; cin >> num;
            istringstream iss(num);
            int a,d=0; char c; string b;
            iss >> a;
            iss.get(c);
            if (c == '.') {
                iss >> b;
                if (b.size() == 1) b += '0';
                if (!b.empty()) d = stoi(b);
            }
            pt = (a*100+(num[0]=='-'?-d:d))+1000*100;
        }
        points[i] = pts;

        ycoords.insert(pts[1]);
        ycoords.insert(pts[3]);
    }

    sort(points.begin(), points.end());


    int last = *ycoords.begin();
    int tot = 0;
    for (auto y : ycoords) {
        if (y == (*ycoords.begin())) continue;
        int prev = -1e9;
        int mx = -1e9;
        for (int i = 0; i < n; i++) {
            if (y - 1 < points[i][1] || y - 1 > points[i][3]) continue;
            if (prev == -1e9) {
                prev = points[i][0];
                mx = points[i][2];
            }
            else if (points[i][0] > mx) {
                tot += (mx - prev) * (y - last);
                prev = points[i][0];
                mx = points[i][2];
            }
            else mx = max(mx, points[i][2]);
        }
        if (prev > -1e6) tot += (mx - prev) * (y - last);
        last = y;
        //cout << y << " " << tot << " " << mx << " " << last << endl;
    }

    int round = (tot%100)/10 >= 5;
    tot /= 100;
    tot += round;
    printf("%lld", tot/100); cout << "."; printf("%02lld\n", tot % 100);
}