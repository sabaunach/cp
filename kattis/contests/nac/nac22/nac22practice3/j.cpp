#include <bits/stdc++.h>

using namespace std;

int N, M;

// mod by N and wrap
int f(int i) {
    return (i % N) + 1;
}

void solve() {
    if (N == M) {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            cout << f(i) << " " << f(i + 1) << endl;
        }
    } else if (M == N * (N - 1) / 2) {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) break;
                cout << f(i) << " " << f(j) << endl;
            }
        }
    } else if (!(N % 2) && M == (N/2)*(N/2)) {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            cout << f(i) << " " << f(i + 1) << endl;
            for (int o = 3; o < N - 2; o += 2) {
                if (i + o >= N) break;
                cout << f(i) << " " << f(i + o) << endl;
            }
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    while (cin >> N >> M && N != -1) {
        solve();
    }
}
