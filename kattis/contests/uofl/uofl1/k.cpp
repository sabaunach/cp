#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    int loc = 1;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        st.push(loc++);
        char in; cin >> in;
        if (in == 'R') {
            while (!st.empty()) {
                cout << st.top() << endl; st.pop();
            }
        }
    }
    while (!st.empty()) {
        cout << st.top() << endl; st.pop();
    }
}