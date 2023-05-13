/* https://icpc.global/community/history-icpc-2008/2008WorldFinalsProblemSet.pdf
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=245&page=show_problem&problem=3510
 */

#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> coeff;
ll d;
string h, e, d_str;
bool readPow = false, readD = false;
int sgn = 1;

vector<vector<ll>> binom(101, vector<ll>(101));

bool solve() {
    int m = 0; for (int i = 0; i < 101; i++) if (coeff[i]) m = i;
    // cout << "d = " << d << ", ";
    // for (int x = m; x >= 0; x--) cout << coeff[x] << " "; cout << "\n";
    binom[0][0] = 1;
    for (int i = 1; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            binom[i][j] = (j > 0 ? binom[i-1][j-1] : 0) + binom[i-1][j];
            binom[i][j] %= d;
        }
    }
    for (int it = 0; it < m; it++) {
        if (coeff[0] % d) return false;
        vector<ll> coeff_2(101);
        for (int i = 0; i < 101; i++) {
            for (int k = 0; k < i; k++) {
                (coeff_2[k] += coeff[i]*binom[i][k]) %= d;
            }
        }
        coeff = coeff_2;
        // for (int x = m; x >= 0; x--) cout << coeff[x] << " "; cout << "\n";
    }
    return coeff[0] % d == 0;
}

void add_coeff() {
    if (h.size()) {
        if (e.size()){
            coeff[stoll(e)] = sgn*stoll(h);
        } else {
            coeff[readPow ? 1 : 0] = sgn*stoll(h);
        }
    }
    h = ""; e = ""; sgn = 1;
    readPow = false; readD = false;
}

int main() {
    string line;
    int t = 1;
    while (getline(cin, line)) {
        if (line[0] == '.') return 0;
        coeff.assign(101, 0);
        readPow = false, readD = false;
        sgn = 1; h = e = d_str = "";
        for (char &c: line) {
            if (c == '+' || c == '-') {
                add_coeff();
                sgn = (c == '+') ? 1 : -1;
            } else if ('0' <= c && c <= '9') {
                if (readPow) e+=c;
                else if (readD) d_str+=c;
                else h+=c;
            } else if (c == 'n') {
                if (h.empty()) h = "1";
                readPow = true;
            } else if (c == ')') {
                add_coeff();
                readD = true; readPow = false;
            }
        }
        d = stoll(d_str);

        // mod coeffs into range [0,d)
//        for (int i = 0; i < 101; i++) {
//            coeff[i] -= d * (coeff[i]/d);
//            (coeff[i] += d) %= d;
//        }

        cout << "Case " << t++ << ": " << (solve() ? "Always an integer" : "Not always an integer") << "\n";
    }
}