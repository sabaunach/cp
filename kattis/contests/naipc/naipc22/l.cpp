#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int min = 999999, minidx = -1;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if (j < min) {
            min = j;
            minidx = i;
        }
    }
    cout << minidx;
}