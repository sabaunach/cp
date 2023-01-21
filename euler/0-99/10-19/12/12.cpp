#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    // TODO: this is definitely not the smart way
    int n = 100000000;
    vector<int> v(n);
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += i) {
            v[j]++;
        }
    }
    for (int i = 1, s = 1; s<n; s += ++i)
        if (v[s]>500) cout << s << endl;
}