#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 0, i = 0;
    char c;
    for (; cin >> c; i++) {
        if (c >= 'A' && c <= 'Z') {
            cnt += (4 - (i % 4)) % 4;
            i = 0;
        }
    }
    cout << cnt;
}