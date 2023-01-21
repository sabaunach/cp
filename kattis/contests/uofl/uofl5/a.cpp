#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[5][150];
int csum[5];
int wsize[5];
int l_cost[5][150];
int r_cost[5][150];
int n;
unordered_map<char, int> c_map = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};



// yikes need to re-code!
int min_asi(const int asi[5]) {

    // min cost of cutting off window w at index i
    vector<vector<int>> r_min_cost(5, vector<int>(n, 99999));
    // min cost of any assignment of windows to the left
    vector<vector<int>> l_min_cost(5, vector<int>(n, 99999));
    for (int i = 0; i < n; i++) {
        r_min_cost[asi[0]][i] = r_cost[asi[0]][i];
    }
    int w_l = wsize[asi[0]];
    for (int w = 1; w < 5; w++) {
        for (int l = max(w_l, 1); l + wsize[asi[w]] - 1 < n; l++) {
            int cost = r_min_cost[asi[w - 1]][l - 1] + l_cost[asi[w]][l];
            l_min_cost[asi[w]][l] = min(l_min_cost[asi[w]][l - 1], cost);
        }
        // compute r_min_cost for this w
        for (int r = max(w_l + wsize[asi[w]] - 1, 0); r < n; r++) {
            r_min_cost[asi[w]][r] = l_min_cost[w][r - wsize[asi[w]] + 1] + r_cost[asi[w]][r];
        }
        // change w_l
        w_l += wsize[asi[w]];
    }
    for (int i = 0; i < 5; i++) {
        cout << asi[i] << " ";
    }
    cout << ": " << r_min_cost[asi[4]][n - 1] << endl;
    return r_min_cost[asi[4]][n - 1];
}

int solve() {
    string s; cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        int cost; cin >> cost;
        int owner = c_map[s[i]];
        c[owner][i] = cost;
        csum[owner] += cost;
    }
    int d; cin >> d;
    while(d--) {
        int i; cin >> i; i--;
        for (int owner = 0; owner < 5; owner++) {
            csum[owner] -= c[owner][i];
            c[owner][i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int owner = 0; owner < 5; owner++) {
            wsize[owner] += (c[owner][i] > 0);
            if (c[owner][i] > 0)
                cout << i << ": " << owner << endl;
        }
    }
    cin >> s;
    for (const auto & ch: s) {
        wsize[c_map[ch]]++;
    }

    // initial costs of specific left, right indices of window, inclusive
    for (int owner = 0; owner < 5; owner++) {
        l_cost[owner][0] = 0;
        for (int i = 1; i < n; i++) {
            l_cost[owner][i] = l_cost[owner][i - 1] + c[owner][i];
        }
        r_cost[owner][n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            r_cost[owner][i] = r_cost[owner][i + 1] + c[owner][i];
        }
    }

    int asi[] = {0,1,2,3,4};
    int res = 99999;
    do {
        res = min(res, min_asi(asi));
    } while (next_permutation(asi,asi+5));
    return res;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cout << solve();

    return 0;
}
