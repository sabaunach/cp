#include <bits/stdc++.h>

using namespace std;

int main() {
    bool sm = false, fr = false;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == ':' && s[i+1] == '(')
            fr = true;
        else if (s[i] == ':' && s[i+1] == ')')
            sm = true;
    }
    if (sm) {
        if (fr) {
            cout << "double agent";
        } else {
            cout << "alive";
        }
    } else if (fr) {
        cout << "undead";
    } else {
        cout << "machine";
    }
    cout << endl;
}