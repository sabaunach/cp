#include <bits/stdc++.h>

using namespace std;

int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int dist(int m1, int d1, int m2, int d2) {
    // i'm so lazy
    int cnt = 0;
    if (m1 == m2 && d1 <= d2) {
        return d2 - d1;
    }
    cnt += months[m1] - d1;
    m1 = (m1 + 1) % 12;
    while (m1 != m2) {
        cnt += months[m1];
        m1 = (m1 + 1) % 12;
    }
    cnt += d2;
    return cnt;
}

int main() {
    vector<vector<bool>> bday(12);
    for (int i = 0; i < 12; i++) {
        bday[i].resize(months[i]);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s; cin >> s;
        stringstream sstr(s);
        string m, d;
        getline(sstr, m, '-');
        getline(sstr, d);
        int mi = stoi(m), di = stoi(d);
        bday[mi - 1][di - 1] = true;
    }

    int maxd, maxm, maxv = 0, cnt = 0;
    int lastm = -1, lastd = -1;
    for (int m = 0; ; m = (m + 1) % 12) {
        int d;
        for (d = 0; d < months[m]; d++) {
            if (m == lastm && d == lastd) break;
            if (bday[m][d]) {
                if (lastm == -1) {
                    lastm = m; lastd = d;
                }
                cnt = 0;
            } else {
                cnt++;
                if (cnt > maxv) {
                    maxv = cnt;
                    maxd = d;
                    maxm = m;
                } else if (cnt == maxv && dist(9,27,m,d) < dist(9,27,maxm,maxd)) {
                    maxd = d;
                    maxm = m;
                }
            }
        }
        if (m == lastm && d == lastd) break;
    }

    cout << (maxm + 1 < 10 ? "0" : "") << maxm + 1 << "-"
    << (maxd + 1 < 10 ? "0" : "") << maxd + 1 << endl;
}
