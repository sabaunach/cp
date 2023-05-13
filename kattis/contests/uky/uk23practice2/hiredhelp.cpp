#include <bits/stdc++.h>

using namespace std;

int N,K;

bool feasible(map<int, int, greater<>> m, int k) {
    // t[i] = minimum time that employee i must work on a shoe
    //  -> if t[i]<=0 then the employee would have to work on a shoe at an infeasible time
    // disperse shoes among employees from last deadline to first
    auto it = m.begin();
    vector<int> t(k, INT_MAX);
    for (int s = 0; s < K; s++) {
        for (int j = 0; j < k; j++) {
            t[j] = min(it->first, t[j]-1);
            if (!--it->second) it++;
        }
    }
    return !any_of(t.begin(), t.end(), [] (auto &a) { return a<=0; });
}

// 0..1
int b_search_pred(map<int, int, greater<>>& v) {
    auto pred = [&] (int m) -> bool {return !feasible(v, m); };
    int l = -1, r = N/K+1;
    while (l + 1 < r) {
        int m = (l+r) / 2;
        if (pred(m)) r = m;
        else l = m;
    }
    return l;
}

int main() {
    cin >> N >> K;
    map<int, int, greater<>> m;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        m[x]++;
    }
//    for (int i = 0; i <= N/K; i++) {
//        cout << i << ": " << feasible(m, i) << endl;
//    }
    cout << b_search_pred(m) << endl;
}


