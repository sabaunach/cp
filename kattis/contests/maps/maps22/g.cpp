#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, char> expect =
            {
                    {"number of", 'c'},
                    {"amount of", 'm'},
                    {"most", 'a'},
                    {"fewest", 'c'},
                    {"least", 'm'},
                    {"more", 'a'},
                    {"fewer", 'c'},
                    {"less", 'm'},
                    {"many", 'c'},
                    {"much", 'm'},
                    {"few", 'c'},
                    {"little", 'm'}
            };
    int n, p;
    cin >> n >> p;
    unordered_map<string, char> noun;
    for(int i = 0; i < n; i++) {
        string s; char c; cin >> s >> c;
        noun[s] = c;
    }
    cin.ignore(100, '\n');
    for(int i = 0; i < p; i++) {
        string line;
        getline(cin, line);
        auto iss = istringstream(line);
        vector<string> words;
        for (string s; iss >> s;)
            words.push_back(s);
        string key = words[0];
        for (int j = 1; j < words.size()-1; j++)
            key += " " + words[j];
        string val = words[words.size()-1];
        if (expect[key] == 'a' || expect[key] == noun[val])
            cout << "Correct!" << endl;
        else
            cout << "Not on my watch!" << endl;
    }
}