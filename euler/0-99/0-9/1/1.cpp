#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    int n = 1000, sum = 0;
    vector<int> v(n); v[3]=1; v[5]=1;
    for (int i = 0; i < n; i++) {
        if (v[i]) sum += i;
        if (i*3<n) v[i*3]=1;
        if (i*5<n) v[i*5]=1;
    }
    cout << sum << endl;
}