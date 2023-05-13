#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7, MOD2=998244353;
int rhash(string& s) {
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        ((res *= 27) += (s[i]-'a'+1)) %= MOD;
    }
    return res;
}

int rhash2(string& s) {
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        ((res *= 27) += (s[i]-'a'+1)) %= MOD2;
    }
    return res;
}

int main() {
    #define int long long
    int n; cin >> n;
    vector<string> v(n);
    for (auto &s: v) cin >> s;

    unordered_map<int, int> d, d2;
    for (int i = 0; i < n; i++) {
        d[rhash(v[i])] = i;
        d2[rhash2(v[i])] = i;
    }

    int cnt = 0;
    vector<int> pows(1e6+2, 1);
    vector<int> pows2(1e6+2, 1);
    for (int i = 1; i < pows.size(); i++) pows[i] = (pows[i-1]*27)%MOD;
    for (int i = 1; i < pows2.size(); i++) pows2[i] = (pows2[i-1]*27)%MOD2;
    for (auto &s: v) {
        int h = rhash(s), h2 = rhash2(s);
        for (int i = 0; i <s.size(); i++) {
            if (i>0) {
                h = ((h + (s[i-1]-'a'+1)*pows[s.size()-i-1])+MOD)%MOD;
                h2 = ((h2 + (s[i-1]-'a'+1)*pows2[s.size()-i-1])+MOD2)%MOD2;
            }
            h = ((h - (s[i]-'a'+1)*pows[s.size()-i-1])+MOD)%MOD;
            h2 = ((h2 - (s[i]-'a'+1)*pows2[s.size()-i-1])+MOD2)%MOD2;
            if (d.count(h) && d2.count(h2)) {
                cnt++;
                cout << s << endl;
                break;
            }
        }
    }
    if (!cnt)
        cout << "NO TYPOS\n";
}