#include <bits/stdc++.h>

using namespace std;
int n;
const int ST = INT_MAX-1, ED = INT_MAX-2;

vector<int> manacher_odd(vector<int> s) {
    s.insert(s.begin(), ST);
    s.push_back(ED);
    vector<int> p(n+2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) p[i]++;
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return {begin(p)+1, end(p)-1};
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> szs = manacher_odd(s),
                incrs(n, 1),
                decrs(n, 1);
    for (int i = s.size()-2; i >= 0; i--) {
        if (s[i] < s[i+1])
            incrs[i] = incrs[i+1]+1;
        else if (s[i] > s[i+1])
            decrs[i] = decrs[i+1]+1;
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
        if (incrs[i] > 1 && i+incrs[i]-1 < n && decrs[i+incrs[i]-1] >= incrs[i])
            ans = max(ans, min(incrs[i], szs[i+incrs[i]-1]));

    ans = (ans-1)*2+1;
    cout << (ans > 2 ? ans : -1) << endl;
}