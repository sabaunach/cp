#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    long long n = 600851475143, ans = 1;
    vector<int> v(sqrt(n)+10);
    for (long long i = 2; i*i < n; i++) {
        if (!v[i]) {
            if (600851475143 % i == 0) ans = i;
            for (long long j = i+i; j*j < n; j += i) {
                v[j] = 1;
            }
        }
    }
    cout << ans << endl;
}