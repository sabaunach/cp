#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)


int main() {
    int n = 4000000;
    int a = 1, b = 2;
    int sum = 0;
    while (b <= n) {
        if (b%2 == 0) sum += b;
        a = b + a;
        swap(a,b);
    }
    cout << sum << endl;
}