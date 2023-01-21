#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    if (n == 1) { cout << "0\n"; return 0; }
    vector<vector<int>> r(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            int x; cin >> x;
            r[i].push_back(x);
        }
    }

    vector<int> v = {0, r[0][1]};
    bool good = true;
    for (int diag = 2; diag < n; diag++) {
        int l = v.back()-r[diag-1][1], u = v.back()+r[diag-1][1];
        if (l == u) { v.push_back(u); continue; }

        int cmn = v.back(), cmx = v.back();
        bool found = false;
        for (int i = diag-2; i >= 0; i--) {
            cmn = min(cmn,v[i]); cmx = max(cmx, v[i]);
            int trg = r[i][diag-i];
            if (max(l,cmx)-min(l,cmn)==trg && max(u,cmx)-min(u,cmn)!=trg) {
                v.push_back(l);
                found = true;
                break;
            } else if (max(l,cmx)-min(l,cmn)!=trg && max(u,cmx)-min(u,cmn)==trg) {
                v.push_back(u);
                found = true;
                break;
            }
        }
        if (!found) { good = false; break; }
    }

    if (!good) {
        v = {0, -r[0][1]};
        for (int diag = 2; diag < n; diag++) {
            int l = v.back()-r[diag-1][1], u = v.back()+r[diag-1][1];
            if (l == u) { v.push_back(u); continue; }

            int cmn = v.back(), cmx = v.back();
            for (int i = diag-2; i >= 0; i--) {
                cmn = min(cmn,v[i]); cmx = max(cmx, v[i]);
                int trg = r[i][diag-i];
                if (max(l,cmx)-min(l,cmn)==trg && max(u,cmx)-min(u,cmn)!=trg) {
                    v.push_back(l);
                    break;
                } else if (max(l,cmx)-min(l,cmn)!=trg && max(u,cmx)-min(u,cmn)==trg) {
                    v.push_back(u);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n-1; i++) cout << v[i] << " ";
    cout << v.back() << "\n";
}