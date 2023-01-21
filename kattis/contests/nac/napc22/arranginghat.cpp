#include <bits/stdc++.h>

using namespace std;

vector<string> nums;
const int MXJ = 200;
string dp[41][MXJ];

// for first num, min # given j changes obtained by setting left digits to 0
// for remaining nums, dp[i][j] = min string s.t. s > dp[i-1][j-dj] && uses dj changes

pair<int, int> comp(const string&a, const string&b, int i=0) {
    int save = 0;
    for (; i < a.size(); i++) {
        if (!save && a[i] != '0') save = i;
        if (a[i] > b[i]) { return {1, i}; }
        if (a[i] < b[i]) { return {-1, -i}; }
    }
    return {0, save};
}

int main() {
    int N, M; cin >> N >> M;
    nums.resize(N+1);
    nums.emplace_back(M, '0');
    for (int i = 0; i < N; i++) {
        cin >> nums[i+1];
    }
    vector<string> prev(MXJ);
    for (int i = 0; i < 200; i++) prev.emplace_back(M, '0');
    vector<string> next(MXJ);
    for (int i = 1; i <= N; i++) {
        string cur = nums[i];
        for (int j = 0; j < MXJ; j++) {
            auto[cmp, idx] = comp(prev[j], cur);

        }
    }
}