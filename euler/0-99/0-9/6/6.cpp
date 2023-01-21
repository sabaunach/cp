#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    int n = 100;
    long long a = (n*(n+1)*(2*n+1))/6, b = n*(n+1)/2;
    cout << b*b - a << endl;
}