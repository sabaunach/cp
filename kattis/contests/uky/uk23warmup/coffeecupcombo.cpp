#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int coffee = 0, tot = 0;
    for (int i = 0; i < n; i++) {
        char in; cin >> in;
        if (in == '1') { coffee = 3; }
        tot += (coffee-- > 0);
    }
    cout << tot << endl;
}
