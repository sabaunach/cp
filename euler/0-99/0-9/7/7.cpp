#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    // x/log x as prime-counting function
    // has <15% error, <10% for n>=10^5, <5% for n>=10^10
    // x/log(x) = 10001
    // in this case x=100000, pi(x) > 10001, works
    int q = 10001;
    int n = 1000000;
    vector<int> v(n);
    for (int i = 2; i < n; i++) {
        if (!v[i]) {
            if (!--q) {
                cout << i << endl;
                return 0;
            }
            for (int j = i+i; j < n; j += i) {
                v[j]=1;
            }
        }
    }
    cout << "fail" << endl;
}