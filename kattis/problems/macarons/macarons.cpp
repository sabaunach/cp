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

ll N, M;
const int MAX_M = 8;
const int MM = pow(2,MAX_M);
Matrix<ll, MM> m;
vector<vector<int>> memo(MM);

vector<int> dfs(int x) {
    if (!memo[x].empty()) return memo[x];
    vector<int> res(MM);
    if (x==MM-1) { res[0]++; return res; }
    int x2 = x;
    for (int i = 0; i < MAX_M; i++) {
         if (!(x2&(1<<i))) {
             x2|=(1<<i);
             auto c = dfs(x2);
             for (int j = 0; j < MM; j++) {
                 res[j] += c[j];
                 res[j|(1<<i)] += c[j];
             }
             if (x2+1 < MAX_M && !(x2&(2<<i))) {
                 c = dfs(x2|(2<<i));
                 for (int j = 0; j < MM; j++) {
                     res[j] += c[j];
                 }
             }
         }
    }
    return memo[x] = res;
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < MM; i++) dfs(i);
    for (int x = 0; x < MM; x++) {
        for (int y = 0; y < MM; y++) {
            if (memo[x].empty()) m.d[x][y] = 0;
            else m.d[x][y] = memo[x][y];
            // printf("%4lld",m.d[x][y]);
        }
        // cout << endl;
    }
    for (int i = 0; i < MAX_M; i++) {
        cout << m.d[0b00000000][1<<i] << " ";
    }
    cout << endl;
}