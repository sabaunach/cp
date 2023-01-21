#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        ull cs = 0, eco = 0;
        vector<int> vcs, veco;
        for (int i = 0; i < n; i++) {
            int in; cin >> in;
            vcs.push_back(in);
            cs += in;
        }
        for (int i = 0; i < m; i++) {
            int in; cin >> in;
            veco.push_back(in);
            eco += in;
        }
        double csavg = cs / (float)n;
        double ecoavg = eco / (float)m;
        int cnt = 0;
        for (auto iq: vcs) {
            if (iq < csavg && iq > ecoavg) cnt++;
        }
        cout << cnt << endl;
    }
}