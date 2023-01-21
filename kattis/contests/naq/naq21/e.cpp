#include <bits/stdc++.h>

using namespace std;

void solve() {
    
}

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    int modifier = 1;
    for (char c: s) {
        if (c == '|') {
            cnt = cnt + modifier;
        } else if (c == '(') {
            modifier = -1;
        }
    }
    if (cnt == 0) {
        cout << "correct";
    } else {
        cout << "fix";
    }
}
