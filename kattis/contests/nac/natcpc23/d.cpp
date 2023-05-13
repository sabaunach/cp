/* https://vjudge.net/contest/556429#problem/A
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 2*1e5+2;

int main() {

    int M = ceil(sqrt(N));
    vector<vector<pair<int, int>>> decomp(M);
    vector<int> lazy(M), sorted(M, true);
    auto update = [&] (int l, int r, int v) {
        for (int i = l/M; i <= r/M; i++) {
            if (i==l/M || i==r/M) {
                for (auto&[val, j]: decomp[i]) {
                    bool a=i==l/M, b=i==r/M, c=j>=l%M, d=j<=r%M;
                    if (a&b&c&d || a&!b&c || !a&b&d) val+=v;
                }
                sorted[i] = false;
            } else {
                lazy[i] += v;
            }
        }
    };
    auto query = [&] (int l, int r) {
        long long tot = 0;
        for (int i = l/M; i <= r/M; i++) {
            if (i==l/M || i==r/M) {
                for (auto&[val, j]: decomp[i]) {
                    bool a=i==l/M, b=i==r/M, c=j>=l%M, d=j<=r%M;
                    if (a&b&c&d || a&!b&c || !a&b&d) tot+=lazy[i]+val != 0;
                }
            } else {
                if (!sorted[i]) sort(decomp[i].begin(), decomp[i].end()), sorted[i] = true;
                tot += M - distance(decomp[i].begin(), upper_bound(decomp[i].begin(), decomp[i].end(), make_pair(-lazy[i], INT_MAX)));
            }
        }
        return tot;
    };

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            decomp[i].push_back({0, j});
        }
    }

    int n; cin >> n;
    multimap<pair<long long, long long>, pair<long long, long long>> m;
    for (int i = 0; i < n; i++) {
        vector<long long> pts(4);
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
        m.insert({{pts[0], 1}, {pts[1],pts[3]}});
        m.insert({{pts[2],-1}, {pts[1],pts[3]}});
    }

    long long area = 0;
    long long x_last = INT_MIN;
    for (auto[k,v]: m) {
        auto[x,sgn] = k;
        auto[y1, y2] = v;
        if (x-x_last) {
            area += (x-x_last)*query(0, N-1);
        }
        update(y1, y2-1, sgn);
        x_last = x;
    }

    int round = (area%100)/10 >= 5;
    area /= 100;
    area += round;
    printf("%lld", area/100); cout << "."; printf("%02lld\n", area % 100);
}