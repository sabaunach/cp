#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 100000;
    int n; cin >> n;
    vector<int> v(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x]++;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (v[i+1] > v[i]) sum += v[i+1]-v[i];
    }
    cout << sum << endl;
}