#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

int main() {
    string s, t; cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));
    vector<vector<pii>> bt(s.size()+1, vector<pii>(t.size()+1));
    int ansv = 0;
    pii ansp = {-1, -1};
    for (int i = 0; i < s.size(); i++) {
        int mxv = 0;
        pii mxp = {-1, -1};
        for (int j = 0; j < t.size(); j++) {
            if (mxv+(s[i]==t[j]) > dp[i][j]) {
                dp[i+1][j] = mxv+(s[i]==t[j]);
                bt[i+1][j] = mxp;
            } else {
                dp[i+1][j] = dp[i][j];
                bt[i+1][j] = bt[i][j];
            }
            if (dp[i][j] > mxv) {
                mxv = dp[i][j];
                mxp = {i,j};
            }
            if (dp[i+1][j] > ansv) {
                ansv = dp[i+1][j];
                ansp = {i+1,j};
            }
        }
    }
    string out;
    while (ansp.fi != -1) {
        out += t[ansp.se];
        ansp = bt[ansp.fi][ansp.se];
    }
    reverse(out.begin(), out.end());
    cout << out << endl;
}