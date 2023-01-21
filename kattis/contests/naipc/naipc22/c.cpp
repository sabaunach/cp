#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    if (m < 8) {
        cout << "unsatisfactory";
    } else {
        cout << "satisfactory";
    }
    return 0;

    // i hate my life

    vector<int> masks1(m);
    vector<int> masks2(m);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < 3; i++) {
            int in; cin >> in;
            masks1[j] |= (1 << (abs(in) - 1));
            if (in > 0) {
                masks2[j] |= (1 << (abs(in) - 1));
            }
        }
    }


    for (int i = 0; i < (1 << m); i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (!((masks1[j] & i) | masks2[j])) {
                flag = false;
                break;
            }
        }
        if (flag) continue;
        cout << "satisfactory";
        return 0;
    }
    cout << "unsatisfactory";
}
