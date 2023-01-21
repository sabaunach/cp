#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    ll n = 2000000, sum = 0;
    vector<int> v(n);
    for (int i = 2; i < n; i++) {
        if (!v[i]) {
            sum += i;
            for (int j = i+i; j < n; j += i)
                v[j] = 1;
        }
    }
    cout << sum << endl;
}