#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    getline(cin, s); getline(cin, t);
    vector<int> cnt_s(128), cnt_t(128);
    for (auto c: s) cnt_s[c]++;
    for (auto c: t) cnt_t[c]++;
    unordered_set<char> sticky;
    for (int i = 'a'; i <= 'z'; i++) if (cnt_t[i] > cnt_s[i]) sticky.insert((char)i);
    if (cnt_t[' '] > cnt_s[' ']) sticky.insert(' ');
    for (auto c: sticky) cout << c;
//    unordered_set<char> sticky;
//    for (int i = 0, j = 0; i < s.size();) {
//        if (s[i] == t[j]) { i++; j++; }
//        else { sticky.insert(t[j++]); }
//    }
//    for (auto c: sticky) cout << c;
}