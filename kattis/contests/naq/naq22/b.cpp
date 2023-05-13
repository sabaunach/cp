#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
ll MOD = 1e9+7;

template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
        rep(k,0,N) (a.d[i][j] += d[i][k]*m.d[k][j]) %= MOD;
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i,0,N) rep(j,0,N) (ret[i] += d[i][j] * vec[j]) %= MOD;
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
        return a;
    }
};


int main() {
    ll A, B; cin >> A >> B;

    // 90x90 adjacency matrix. states (sum % 9, last digit)
    Matrix<ll, 90> m;
    for (int d = 0; d < 10; d++) {
        for (int s = 0; s < 9; s++) {
            for (int new_digit = 0; new_digit < 10; new_digit++) {
                if (new_digit == d) continue; // can't have two same adjacent digits
                m.d[s*10 + d][((s+new_digit)%9)*10 + new_digit] = 1;
            }
        }
    }
    // edge cases
    if (A==1) {
        cout << (B<10) << "\n";
        return 0;
    }
    if (A==2) {
        cout << (10 <= B && B < 100 && B/10 != B%10) << "\n";
        return 0;
    }

    // # k-length walks from i to j = (A^k)_ij
    // take matrix to power (# digits)-3
    // as we are going to fix the first three digits
    m = m^(A-3);
    ll tot = 0;
    for (int i = 0; i < 4; i++) {
        // possible choices for last 2 digits (based on %25)
        int m25 = B%25 + i*25;
        int last = m25%10, last2 = m25/10;
        if (last == last2) continue; // can't have two same adjacent digits

        // target sum: we want # ways to get to sum of (B - m25)%9
        int sum = (B-m25+108)%9;

        // set the starting digit, as we can't have starting digit = first digit of our last 2 digits
        for (int start_d = 0; start_d < 10; start_d++) {
            if (start_d == last2) continue;

            // count # walks from (start digit, sum=0) to (last_digit, target_sum-start_d)
            for (int last_d = 1; last_d < 10; last_d++) {
//                if (m.d[start_d][((sum-start_d+9)%9)*10 + last_d])
//                    cout << last_d << ".." << start_d << last2 << last << " with sum " << sum << "\n";
                (tot += m.d[start_d][((sum-start_d+9)%9)*10 + last_d]) %= MOD;
            }
        }
    }
    cout << tot << "\n";
}