#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    for (int a = 1; a < 1000; a++) {
        for (int b = a+1; 1000-a-b > b; b++) {
            int c = 1000-a-b;
            if (a*a+b*b == c*c) {
                cout << a*b*c << endl;
                return 0;
            }
        }
    }
    cout << "fail\n";
}