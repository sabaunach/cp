#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    string s2 = s + s;
    reverse(s.begin(), s.end());
    cout << (s2.find(s) != string::npos);
}