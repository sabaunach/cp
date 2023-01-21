#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    stack<int> st;
    while (n--) {
        int in; cin >> in;
        if (st.size() && (st.top() + in) % 2 == 0) st.pop();
        else st.push(in);
    }
    cout << st.size() << endl;
}