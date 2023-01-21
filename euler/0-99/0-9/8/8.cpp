#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    string s, l; int q;
    cin >> q;
    while (getline(cin, l)) s += l;
    int n = s.size(), z=0;
    long long prod = 1, ans=0;
    for (int i = 0; i < n; i++) {
        if (s[i]=='0') {
            prod = 1;
            z = i+1;
        }
        else {
            prod *= s[i]-'0';
            if (i-z>=q) {
                prod /= s[i-q]-'0';
            }
            UMAX(ans, prod);
        }
    }
    cout << ans << endl;
}