//
// uky-bbb
// room gh316
//
#include <bits/stdc++.h>
using namespace std;

double h[20];
double h_[20];
double ev[1048577];
bool vis[1048577];

double dfs(int state) {
    if (!vis[state]) {
        vector<int> v;
        for (int i =0 ; i < 20; i++)
            if(state & (1<<i)) {
                v.push_back(i);
            }
        if (v.size() == 2) {
            ev[state] = 0.0;
        } else {
            double totw = 1.0, totb = 1.0;
            for (int i: v) {
                totw *= h[i];
                totb *= h_[i];
            }
            double totp = 0.0;
            vector<double> p(20);
            for (int i: v) {
                p[i] = (totw)*h_[i]/h[i] + (totb)*h[i]/h_[i];
                totp += p[i];
            }
            double totev = 0.0;
            for (int i: v) {
                totev += p[i]*dfs(state & (~(1<<i)));
            }
            totev = totev / totp;
            totev += 1 / totp;
            ev[state] = totev;
        }
    }
    vis[state] = true;
    return ev[state];
}


int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        h_[i] = 1.0 - h[i];
    }
    cout << setprecision(15) << dfs((1<<n) - 1);
}

