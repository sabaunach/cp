#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    int cnt = 1;
    while (cin >> n) {
        if (n == 0) return 0;
        string temp;
        getline(cin,temp);
        map<string, int> name_cnt;
        cout << "List " << cnt++ << ":" << endl;
        while (n--) {
            string s;
            getline(cin, s);
            std::istringstream ss(s);
            std::string token;
            while(std::getline(ss, token, ' '));
            transform(token.begin(), token.end(), token.begin(), ::tolower);
            name_cnt[token]++;
        }

        for (auto k_v: name_cnt) {
            cout << k_v.first << " | " << k_v.second << endl;
        }
    }
}