#include <bits/stdc++.h>

#define int unsigned long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> fish(n);
    for (int i = 0; i < n; i++) {
        cin >> fish[i];
    }
    vector<pair<int, int>> mongers(m);
    for (int i = 0; i < m; i++) {
        pair<int, int> monger;
        cin >> monger.second >> monger.first;
        mongers[i] = monger;
    }
    sort(fish.begin(), fish.end());
    reverse(fish.begin(), fish.end());
    sort(mongers.begin(), mongers.end());
    reverse(mongers.begin(), mongers.end());
    int res = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (mongers[j].second == 0) {
            j++; continue;
        }
        res += mongers[j].first * fish[i];
        i++;
        mongers[j].second -= 1;
    }
    cout << res;
}