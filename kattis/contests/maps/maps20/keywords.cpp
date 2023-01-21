#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    unordered_set<string> words;
    getline(cin, str);
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '-')
                str[i] = ' ';
            str[i] = tolower(str[i]);
        }
    words.insert(str);
    }
    cout << words.size();
}
