#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int c, n, m;
    cin >> c >> n >> m;
    vector<int> farms;

    ull cnt = 0;
    for (int i = 0; i < n; i++) {
        int in; cin >> in;
        farms.push_back(in);
        cnt++;
    }
    make_heap(farms.begin(), farms.end());

    vector<int> days;
    for (int i = 0; i < m; i++) {
        int in; cin >> in;
        days.push_back(in);
    }
    vector<int> days_unsorted = days;
    sort(days.begin(), days.end());
    reverse(days.begin(), days.end());
    vector<ull> res = vector<ull>(51);

    ull doublingFarms = 0;
    for (int day = 0; day <= 50; day++) {
        if (day == days.back()) {
            res[day] = cnt;
            days.pop_back();
        }
        for (size_t i = 0; i < farms.size(); i++) {
            farms[i] *= 2;
        }
        while (!farms.empty() && farms[0] > c) {
            pop_heap(farms.begin(), farms.end());
            farms.pop_back();
            doublingFarms++;
        }
        cnt += doublingFarms;
        doublingFarms *= 2;
    }
    for (int day: days_unsorted) {
        cout << res[day] << endl;
    }
}
