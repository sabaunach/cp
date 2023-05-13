// backsolve

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i,a,b) for (int i = a; i < (b); ++i)

int n,m;
vector<int> unpack(int rep) {
    vector<int> st;
    rep(i,0,n) st.push_back(rep%3), rep/=3;
    return st;
}

char cnv(int x) {
    return "CIP"[x];
}

const int MOD = 998244353;

int32_t main() {
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    int tot = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> g[i][j];
        if (g[i][j] == '?') (tot *= 3) %= MOD;
    }
    int max_st = pow(3,n);

    vector<vector<int>> adj(max_st);

    for (int a = 0; a < max_st; a++) {
        for (int b = 0; b < max_st; b++) {
            auto a_st = unpack(a), b_st = unpack(b);
            bool flag = false;
            for (int k = 0; k < n-1; k++) if (cnv(a_st[k]) == 'I' && cnv(a_st[k+1]) == 'P' && cnv(b_st[k]) == 'C' && cnv(b_st[k+1]) == 'C') {
                    flag = true; break;
            }
            if (flag) continue;
            adj[a].push_back(b);
        }
    }

//    vector<vector<int>> valid(m, vector<int>(max_st));
//    for (int a = 0; a < max_st; a++) {
//        for (int j = 0; j < m; j++) {
//            auto a_st = unpack(a);
//            bool flag = false;
//            for (int i = 0; i < n; i++) if (g[i][j] != '?' && cnv(a_st[i]) != g[i][j]) {
//                    flag = true; break;
//                }
//            if (flag) continue;
//            valid[j][a] = 1;
//        }
//    }

//    vector<vector<int>> cnt(m, vector<int>(max_st));
//
//    cnt[0] = valid[0];
//
//    for (int j = 1; j < m; j++) {
//        for (int prev_rep = 0; prev_rep < max_st; prev_rep++) {
//            for (auto& cur_rep: adj[prev_rep]) {
//                if (valid[j][cur_rep])
//                    (cnt[j][cur_rep] += cnt[j-1][prev_rep]) %= MOD;
//            }
//        }
//    }
//
//    int sum = 0;
//    for (int i = 0; i < max_st; i++) (sum += cnt[m-1][i]) %= MOD;
//    cout << (tot - sum + MOD) % MOD << "\n";
}