#include <bits/stdc++.h>

using namespace std;

// SIZE should be 1 + a power of 2.
const int SIZE = 262145; // 2^18 + 1 > 200000
int A[262145];

const int MAXN = 5000, N = 10;

// Least Significant Bit of i
#define LSB(i) ((i) & -(i))

int BIT[MAXN + 1];
void update(int x, int val) {++x; while(x<=N) {
    BIT[x]+=val;  x+=LSB(x); } }

int query(int x) {  ++x;  int res=0;  while(x>0)  {
    res+=BIT[x];  x-=LSB(x);  } return res; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        update(i, 10 - i);
    }
    for (int i = 0; i < 10; i++) {
        cout << query(i) << endl;
    }
}

// Returns the sum of the first i elements (indices 0 to i)
// Equivalent to range_sum(0, i)
int prefix_sum(int i) {
    int sum = A[0];
    for (; i != 0; i -= LSB(i))
        sum += A[i];
    return sum;
}

// Add delta to element with index i (zero-based)
void add(int i, int delta) {
    if (i == 0) {
        A[0] += delta;
        return;
    }
    for (; i < SIZE; i+= LSB(i))
        A[i] += delta;
}

void solve() {

}

