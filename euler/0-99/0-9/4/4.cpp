#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    int n = 3, ans = 0;
    for (int i = pow(10, n-1); i < (int)pow(10, n); i++) {
        for (int j = pow(10, n-1); j < (int)pow(10, n); j++) {
            auto p = to_string(i*j);
            for (int k = 0; k < p.size()/2; k++) {
                if (p[k]!=p[p.size()-k-1]) {
                    p = ""; break;
                }
            }
            if (!p.empty()) UMAX(ans,i*j);
        }
    }
    cout << ans << endl;
}